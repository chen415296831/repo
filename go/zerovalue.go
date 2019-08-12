package main
import "fmt"

//define datastruct
type  Node struct {
	next *Node
	val int
}
func main()	{
	var str1 string
	//if str1 { } 这种方式不行
	if str1 == "" {
		fmt.Println("str1 zeroed")
	}

	var pNode *Node
	//虽然pNode是指针，但也不能 if pNodd
	if pNode == nil {
		fmt.Print("pNode non-zeroed")
	}
}
