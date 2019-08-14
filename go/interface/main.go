package main

import "fmt"

type person struct {
	age   int
	email string
}

type Modfier interface {
	showAge()
	setEmail(string)
}

func (p person) showAge() {
	fmt.Printf("age : %d\n", p.age)
}

func (p *person) setEmail(email string) {
	p.email = email
	fmt.Printf("person set email as %s\n", p.email)
}


type student struct {
	person
	grade int
}

func (me *student) setEmail(email string) {
	me.email = email + "set by student type"
	fmt.Printf("student set email as %s\n", me.email)
}

func main() {
	user1 := person{12, ""}

	//person 的setEmail方法 接收者是指针类型的，
	//把实体赋值给接口，必须使用指针类型的
	//var u Modfier = &user1  //这样编译报错
	var u Modfier = &user1

	u.setEmail("123@gmail.com")
	u.showAge()

	stu1 := student{person{13, "abc@gmail.com"}, 5}
	//可以直接访问
	stu1.showAge()
	//借助类型名访问,访问内部类型的实现
	stu1.person.setEmail("xyz@gmail.com")
	//直接调用方法，访问外部类型的实现
	stu1.setEmail("ijk@gmail.com")

	//student 也实现了Modfier接口
	u = &stu1
	u.showAge()
	//接口只能访问外部类型的方法
	u.setEmail("interface@gmail.com")
}
