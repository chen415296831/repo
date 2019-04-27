#!/usr/bin/python3

class student:
    schoolName ="midle" #shared by all instances
    def __init__(self, name, age, school):
        self.name = name
        self.age = age
        student.schoolName = school
    def showinfo(self):
        print ("name: ", self.name, "age: ", self.age, "school: ", student.schoolName)
    def __str__():
        return "({0}:{1})".format(self.name,self.age)
class moniter(student):
    #def __init__(self, name, age, jobs,school):
        #调用基类的__init__函数,如果不这样，基类的__init__函数不会调用
        #When a class defines an __init__() method, class instantiation 
        #automatically invokes __init__() for the newly-created class instance
    #    student.__init__(self,name, age, school)
    #    self.job = jobs

    def __init__(self, name, age, jobs,school):
        #https://stackoverflow.com/questions/222877/what-does-super-do-in-python
        #super(moniter,self).__init__(name, age, school)
        super().__init__(name, age, school) #python3 可以直接super,不需要传参,不需要对父类硬编码，但是多继承的时候不要使用super，因为会启动复杂的函数决议(Method Resolution Order)
        self.job = jobs
    def __str__(self):
        return "({0}:{1}:{2})".format(self.name, self.age, self.job)

liming = student("liming", 12, "xinhua")
liming.showinfo()
chenguang = student("chenguang", 12, "chaoyang")
chenguang.showinfo()
liming.showinfo()

lihua = moniter("lihua", 15, "banzhuang", "shuguang")
print (lihua)

