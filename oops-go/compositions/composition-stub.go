package compositions

type Engine struct {
	Power int
}

type Car struct {
	Engine // embedding Engine struct
	Brand  string
}
