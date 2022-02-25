#!/bin/bash
# modified from https://github.com/pypa/python-manylinux-demo
# run docker from root directory of BATS.py
# sudo docker run --rm -e PLAT=manylinux2014_x86_64 -v `pwd`:/io quay.io/pypa/manylinux2014_x86_64 bash /io/build_wheels.sh
# sudo docker run --rm -e PLAT=manylinux_2_24_x86_64 -v `pwd`:/io quay.io/pypa/manylinux_2_24_x86_64 bash /io/build_wheels.sh

#set -e -u -x
set -u -x

function repair_wheel {
    wheel="$1"
    if ! auditwheel show "$wheel"; then
        echo "Skipping non-platform wheel $wheel"
    else
        auditwheel repair "$wheel" --plat "$PLAT" -w /io/wheelhouse/
    fi
}


# Install a system package required by our library
# yum install -y atlas-devel
# yum install -y libjpeg-devel # centOS
apt update
apt install -y libjpeg-dev # debian

# Compile wheels
for PYBIN in /opt/python/*/bin; do
    # "${PYBIN}/pip" install -r /io/build_requirements.txt
    "${PYBIN}/pip" wheel /io/ --no-deps -w wheelhouse/
done

# Bundle external shared libraries into the wheels
for whl in wheelhouse/*.whl; do
    repair_wheel "$whl"
done

# Install packages and test
for PYBIN in /opt/python/*/bin; do
    "${PYBIN}/pip" install -r /io/requirements.txt
    "${PYBIN}/pip" install bats-tda --no-index -f /io/wheelhouse
    "${PYBIN}/python3" -m unittest discover -s /io/test/ -p *.py
done
