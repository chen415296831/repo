class simple:
    instance_cnt = 0
    instance_list = []
    def __init__(self, name):
        self.name = name
        self.number = simple.instance_cnt
        simple.instance_cnt = simple.instance_cnt + 1
        simple.instance_list.append(self)
    @staticmethod
    def show_cnt():
        print ("chicken")

