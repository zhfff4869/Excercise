def logging(level): #2,11
    def wrapper(func):  #3,6,12,15
        def inner_wrapper(*args, **kwargs): #7,16,21,31
            print('[{level}]: enter function {func}()'.format(  #22,32
                level=level,    #23,33
                func=func.__name__))    #24,34
            return func(*args, **kwargs)    #25,28,35,38
        return inner_wrapper    #8,17
    return wrapper  #4,13

@logging(level='INFO')  #1,5,9,26
def say(something):
    print('say {}!'.format(something))  #27

# 此处使用的@语法，等同于
# say = logging(level='INFO')(say)
@logging(level='DEBUG') #10,14,18,36
def do(something):
    print('do {}...'.format(something)) #37

if __name__ == '__main__':  #19
    say('hello')    #20,29
    do('my work')   #30,39

"""
[INFO]: enter function say()
say hello!
[DEBUG]: enter function do()
do my work...
"""
