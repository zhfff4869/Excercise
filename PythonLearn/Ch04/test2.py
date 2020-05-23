class logging(object):  #1,4
    def __init__(self, level='INFO'):   #2,6
        self.level = level  #7

    def __call__(self, func):  # 接受函数,3,9
        def wrapper(*args, **kwargs):   #10,14
            print('[{level}]: enter function {func}()'.format(  #15
                level=self.level,   #16
                func=func.__name__))    #17
            func(*args, **kwargs)   #18,21

        return wrapper  # 返回函数,11

@logging(level='INFO')  #5,8,12,19
def say(something): #
    print('say {}'.format(something))   #20

say('love you.')    #13,22
print(say.__name__)  # wrapper,23


