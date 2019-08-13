
package main

//也可使使用相对路径
import "./db"
import "./mynet"

//去GOPATH中寻找(在package中的src文件中查找)
//import "db"
//import "mynet"

//func main must have no arguments and no return values
func main() {
	//package name similar with namespace
	//首字母大写的才算public
	db.ApidbPrint()
	mynet.ApinetPrint()
}
