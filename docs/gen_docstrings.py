import bats
import inspect

module_name = 'bats'
with open(module_name + '.md', 'w') as file:
    if eval(module_name + '.__doc__') is not None:
        file.write(eval(module_name + '.__doc__') + '\n')
    for c in dir(eval(module_name)):
        if c[:2] == '__':
            continue
        file.write('## {}'.format(c) + '\n')
        if eval(module_name + '.' + c + '.__doc__') is not None:
            file.write(eval(module_name + '.' + c + '.__doc__') + '\n')
        if not inspect.isclass(eval(module_name + '.' + c)):
            # don't recurse for things that are not a class
            #print("  not a class!")
            continue
        for m in dir(eval(module_name + '.' + c)):
            if m[:2] == '__' and m != '__init__':
                continue
            file.write('### {}'.format(m) + '\n')
            file.write(eval(module_name + '.' + c + '.' + m + '.__doc__') + '\n')
