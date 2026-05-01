// Concrete Factory
package main

type Adidas struct{}

func (a *Adidas) makeShoes() IShoes {
	return &AdidasShoes{
		Shoe: Shoe{
			logo: "Adidas",
			size: 14,
		},
	}
}

func (a *Adidas) makeShirt() IShirt {
	return &AdidasShirt{
		Shirt: Shirt{
			logo: "Adidas",
			size: 10,
		},
	}
}
