package main

import (
	"fmt"
)

type Speed float64

const (
	MPH Speed = 1
	KPH Speed = 1.60934
)

type Color string

const (
	BlueColor  Color = "blue"
	GreenColor Color = "green"
	RedColor   Color = "red"
)

type Wheels string

const (
	SportsWheel Wheels = "sports"
	SteelWheel  Wheels = "steel"
)

type Builder interface {
	Color(Color) Builder
	Wheels(Wheels) Builder
	TopSpeed(Speed) Builder
	Build() Vehicle
}

type Vehicle interface {
	Drive() error
	Stop() error
}

// Car is the product
type Car struct {
	color    Color
	wheels   Wheels
	topSpeed Speed
}

func (c *Car) Drive() error {
	fmt.Printf("Driving a %s car with %s wheels at %.2f speed\n", c.color, c.wheels, c.topSpeed)
	return nil
}

func (c *Car) Stop() error {
	fmt.Println("Stopping the car")
	return nil
}

// CarBuilder is the concrete builder
type CarBuilder struct {
	car *Car
}

func NewCarBuilder() *CarBuilder {
	return &CarBuilder{car: &Car{}}
}

func (cb *CarBuilder) Color(color Color) Builder {
	cb.car.color = color
	return cb
}

func (cb *CarBuilder) Wheels(wheels Wheels) Builder {
	cb.car.wheels = wheels
	return cb
}

func (cb *CarBuilder) TopSpeed(speed Speed) Builder {
	cb.car.topSpeed = speed
	return cb
}

func (cb *CarBuilder) Build() Vehicle {
	return cb.car
}

// Director orchestrates the building
type Director struct {
	builder Builder
}

func NewDirector(builder Builder) *Director {
	return &Director{builder: builder}
}

func (d *Director) ConstructSportsCar() Vehicle {
	return d.builder.Color(RedColor).Wheels(SportsWheel).TopSpeed(200 * MPH).Build()
}

func (d *Director) ConstructFamilyCar() Vehicle {
	return d.builder.Color(BlueColor).Wheels(SteelWheel).TopSpeed(100 * MPH).Build()
}

func main() {
	builder := NewCarBuilder()
	director := NewDirector(builder)

	sportsCar := director.ConstructSportsCar()
	sportsCar.Drive()
	sportsCar.Stop()

	familyCar := director.ConstructFamilyCar()
	familyCar.Drive()
	familyCar.Stop()
}
