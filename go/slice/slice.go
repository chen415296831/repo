package main

import "fmt"

//slice是一种动态数组,底层包含三个数据：底层数组指针,长度，容量
//	___________________
// | 指针 | 长度| 容量 |
// --------------------
//   |
//   |
//  \ /
//   |
//	____________________
//	|
//  |---------------------
//

func main() {
	//创建slice
	//[]type 方括号中不指定大小，就是动态啦
	slice1 := make([]string, 5)		//len,cap 都是5
	slice1[0] = "slice1"
	slice2 := make([]string, 4, 5)   //len:3, cap 5
	slice2[0] = "slice2"
	//
	//通过字面值
	slice3 := []string {"read", "black"}
	fmt.Printf("slice3 len : %d \n", len(slice3))

	slice4 := []string{99:""} //len, cap都是100
	fmt.Printf("slice4 len : %d \n", len(slice4))

	//创建切片的切片
	//newslice := slice[i,j]
	//newslice'len == j - i
	//newslice'cap == slice'cap - i
	slice5 := slice1[1:3] //len:2, cap:4
	fmt.Printf("new slice5 len: %d, cap %d\n", len(slice5), cap(slice5))

	//新切面和老切片共享地城的数组
	//当新切片的cap不够时，重新分配内存. 这说明容量够的时候，会在对方不知情的情况下,修改掉数据
	slice5 = append(slice5, "a") //len:3 cap:4
	slice5 = append(slice5, "b") //len:4 cap:4
	slice5 = append(slice5, "d") //重新分配内存

}
