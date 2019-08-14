package main

import "fmt"

func main() {

	//映射内部的数据结构是哈希表

	//创建映射
	//map[key_type]value_type
	colors := make(map[string]string)

	colors["red"] = "#da1337"

	//获取应设置并判断是否存在
	vaule, exits := colors["red"]
	if exits {
		fmt.Println("vaule")
	}

	//删除键值对
	delete(colors, "red")

	for key, vaule := range colors {
		fmt.Printf("%s : %s\n", key, vaule)
	}
}
