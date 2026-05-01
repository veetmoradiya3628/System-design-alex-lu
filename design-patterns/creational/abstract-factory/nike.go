// Concrete Factory
package main

type Nike struct{}

func (n *Nike) makeShoes() IShoes {
	return &NikeShoes{
		Shoe: Shoe{
			logo: "Nike",
			size: 12,
		},
	}
}

func (n *Nike) makeShirt() IShirt {
	return &NikeShirt{
		Shirt: Shirt{
			logo: "Nike",
			size: 10,
		},
	}
}
