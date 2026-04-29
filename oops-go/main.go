package main

import (
	"fmt"

	"example.com/oops-go/class"
	"example.com/oops-go/compositions"
	"example.com/oops-go/interfaces"
)

func main() {
	// fmt.Println("Hello, World!")

	// oops - structs and methods
	u := class.User{Name: "Alice", Age: 24}
	fmt.Println(u.Greet())

	u.SetBalance(10.4)
	fmt.Printf("Balance: %.2f\n", u.GetBalance())

	u.AddBalance(5.6)
	fmt.Printf("Updated Balance: %.2f\n", u.GetBalance())

	// oops - interfaces
	var circle interfaces.Shape = interfaces.Circle{Radius: 5}
	var rectangle interfaces.Shape = interfaces.Rectangle{Width: 4, Height: 6}
	var square interfaces.Shape = interfaces.Square{Side: 3}

	fmt.Printf("Circle Area: %.2f\n", circle.Area())
	fmt.Printf("Rectangle Area: %.2f\n", rectangle.Area())
	fmt.Printf("Square Area: %.2f\n", square.Area())

	// oops - compositions
	var car = compositions.Car{
		Engine: compositions.Engine{Power: 150},
		Brand:  "Toyota",
	}
	fmt.Printf("Car Brand: %s, Engine Power: %d\n", car.Brand, car.Power)

	// oops - constructor pattern
	user := class.NewUser("Veet", 24)
	fmt.Printf("User: %s, Age: %d\n", user.Name, user.Age)
}
