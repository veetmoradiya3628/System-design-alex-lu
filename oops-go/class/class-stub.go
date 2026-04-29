package class

type User struct {
	Name string // public field
	Age  int

	balance float64 // private field
}

// Constructor function to create a new User instance - its constructor pattern, not a real constructor like in other languages
func NewUser(name string, age int) *User {
	return &User{Name: name, Age: age}
}

func (u User) Greet() string {
	return "Hello, " + u.Name + "!"
}

func (u *User) SetBalance(amount float64) {
	u.balance = amount
}

func (u User) GetBalance() float64 {
	return u.balance
}

func (u *User) AddBalance(amount float64) {
	u.balance += amount
}
