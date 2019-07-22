package main

import "fmt"

func main()	{
	//传统方式定义数组
	var  array1  [5]int	//数组的每个元素自动初始化零值
	sum := 0
	//range on arrays and slices provides both the index and value for each entry.
	for _, i := range array1 {
		sum += i
	}
	fmt.Println("array1 sum: ", sum)
	fmt.Println("array1 len: ", len(array1))

	//具体初始化每个元素
	array2 := [5]int{1,2,3,4,5}		//使用 :=定义必须用{}给初始值
	sum = 0
	for _, i := range array2 {
		sum += i
	}
	fmt.Println("array2 sum: ", sum)

	//如果只初始化一部分呢？
	array3 := [5]int{1, 2, 3, 4}
	sum = 0
	for _, i := range array3 {
		sum += i
	}
	fmt.Println("array3 sum: ", sum)
	//答案是OK，没有初始化的还是自动初始化为零值

	//使用下表访问,数组的下标从0开始
	array3[4] = 5

	//如果访问越界呢？
	//array3[5] = 1000
	//编译不通过，编译器很给力呀！其实这是静态访问，现代的编译器都可以检测出来错误
	//使用一个变脸作为下标访问，那就是另一回儿事了

	//使用...自动确定大小
	array4 := [...]int {1,2,4}
	fmt.Println("array4 len: ", len(array4))


	//当然，数组中的元素可以是任意类型
	//复古一下，指针数组
	ptrArray := [2]*int{}
	ptrArray[0] = new(int)

	//数组赋值
	array1 = array3

	//var array4 [4]int
	//array5 = array1 array4是 [4]int类型, array1是[5]int类型，类型不一致，赋值编译报错


	var strPtrArray1 [2]*string
	strPtrArray2 := [2]*string {new(string), new(string)}
	*strPtrArray2[0] = "red"
	*strPtrArray2[1] = "bulu"
	strPtrArray1 = strPtrArray2
	*strPtrArray1[0] = "black"
	println("strPtrArray2[0]: ", *strPtrArray2[0])
}
