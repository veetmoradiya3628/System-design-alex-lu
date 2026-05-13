package main

import "fmt"

type OrderStatus int

const (
	StatusPlaced OrderStatus = iota
	StatusConfirmed
	StatusShipped
	StatusDelivered
	StatusCancelled
)

func (s OrderStatus) String() string {
	names := [...]string{"PLACED", "CONFIRMED", "SHIPPED", "DELIVERED", "CANCELLED"}
	if int(s) < len(names) {
		return names[s]
	}
	return "UNKNOWN"
}

type PaymentMethod struct {
	DisplayName string
	FeePercent  float64
}

var (
	CreditCard = PaymentMethod{"Credit Card", 2.5}
	DebitCard  = PaymentMethod{"Debit Card", 1.0}
	UPI        = PaymentMethod{"UPI", 0.0}
	NetBanking = PaymentMethod{"Net Banking", 1.5}
)

type Order struct {
	orderID       string
	status        OrderStatus
	paymentMethod PaymentMethod
	amount        float64
}

func NewOrder(orderID string, paymentMethod PaymentMethod, amount float64) *Order {
	return &Order{
		orderID:       orderID,
		status:        StatusPlaced,
		paymentMethod: paymentMethod,
		amount:        amount,
	}
}

func (o *Order) AdvanceStatus() bool {
	switch o.status {
	case StatusPlaced:
		o.status = StatusConfirmed
		return true
	case StatusConfirmed:
		o.status = StatusShipped
		return true
	case StatusShipped:
		o.status = StatusDelivered
		return true
	default:
		return false
	}
}

func (o *Order) Cancel() bool {
	if o.status == StatusPlaced || o.status == StatusConfirmed {
		o.status = StatusCancelled
		return true
	}
	return false
}

func (o *Order) GetTotalWithFees() float64 {
	return o.amount + (o.amount * o.paymentMethod.FeePercent / 100)
}

func (o *Order) DisplayInfo() {
	fmt.Printf("Order %s | Status: %s | Payment: %s | Amount: $%.2f (with fees: $%.2f)\n",
		o.orderID, o.status, o.paymentMethod.DisplayName, o.amount, o.GetTotalWithFees())
}

func main() {
	order := NewOrder("ORD-001", CreditCard, 99.99)
	order.DisplayInfo()

	order.AdvanceStatus() // PLACED -> CONFIRMED
	order.AdvanceStatus() // CONFIRMED -> SHIPPED
	order.DisplayInfo()

	fmt.Printf("Cancel after shipping: %v\n", order.Cancel()) // false
}
