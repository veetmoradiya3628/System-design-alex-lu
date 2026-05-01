// Abstract Factory Interface

package main

import "fmt"

type ISportsFactory interface {
	makeShoes() IShoes
	makeShirt() IShirt
}

func GetSportsFactory(brand string) (ISportsFactory, error) {
	switch brand {
	case "nike", "Nike":
		return &Nike{}, nil
	case "adidas", "Adidas":
		return &Adidas{}, nil
	default:
		return nil, fmt.Errorf("Unknown brand: %s", brand)
	}
}
