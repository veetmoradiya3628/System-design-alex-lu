package main

import "fmt"

type FoodOrder struct {
	orderId      string
	customerName string
	items        []string
	totalAmount  float64
	isPlaced     bool
}

func NewFoodOrder(orderId, customerName string) *FoodOrder {
	return &FoodOrder{
		orderId:      orderId,
		customerName: customerName,
		items:        []string{},
		totalAmount:  0.0,
		isPlaced:     false,
	}
}

// AddItem only allows adding items before the order is placed
func (o *FoodOrder) AddItem(name string, price float64) {
	if o.isPlaced {
		fmt.Println("Cannot modify a placed order.")
		return
	}
	o.items = append(o.items, name)
	o.totalAmount += price
}

// PlaceOrder places the order if it has at least one item and hasn't been placed yet
func (o *FoodOrder) PlaceOrder() bool {
	if o.isPlaced || len(o.items) == 0 {
		return false
	}
	o.isPlaced = true
	return true
}

func (o *FoodOrder) GetItemCount() int {
	return len(o.items)
}

func (o *FoodOrder) DisplayOrder() {
	status := "PENDING"
	if o.isPlaced {
		status = "PLACED"
	}
	fmt.Printf("Order %s (%s) - %s\n", o.orderId, o.customerName, status)
	for _, item := range o.items {
		fmt.Printf("  - %s\n", item)
	}
	fmt.Printf("  Total: $%.2f\n", o.totalAmount)
}

func main() {
	order1 := NewFoodOrder("ORD-101", "Alice")
	order1.AddItem("Pizza", 12.99)
	order1.AddItem("Garlic Bread", 4.99)
	order1.AddItem("Coke", 2.49)
	order1.PlaceOrder()

	order2 := NewFoodOrder("ORD-102", "Bob")
	order2.AddItem("Burger", 9.99)
	order2.AddItem("Fries", 3.99)

	order1.DisplayOrder()
	fmt.Println()
	order2.DisplayOrder()
}
