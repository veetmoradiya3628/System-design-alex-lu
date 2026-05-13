package main

import "fmt"

type BankAccount struct {
	// balance is unexported, meaning it cannot be accessed directly from outside the package
	balance float64
	// Name and Type are exported fields, meaning they can be accessed from outside the package
	Name string
	Type string
}

func NewBankAccount(name string, accountType string) *BankAccount {
	return &BankAccount{
		balance: 0.0,
		Name:    name,
		Type:    accountType,
	}
}

func (b *BankAccount) Deposit(amount float64) {
	if amount > 0 {
		b.balance += amount
	}
}

func (b *BankAccount) Withdraw(amount float64) {
	if amount > 0 && amount <= b.balance {
		b.balance -= amount
	}
}

func (b *BankAccount) GetBalance() float64 {
	return b.balance
}

func main() {
	account := NewBankAccount("Alice", "Savings")
	account.Deposit(1000)
	account.Withdraw(200)
	fmt.Println("Account Holder:", account.Name)
	fmt.Println("Account Type:", account.Type)
	fmt.Println("Current Balance:", account.GetBalance())
	fmt.Println("Balance : ", account.balance) // This will work but it's not recommended to access balance directly
}
