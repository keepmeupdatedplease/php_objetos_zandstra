<?php
	abstract class Products_ShopProductWriter {
		protected $products = array();
		
		public function addProduct (Products_ShopProduct $shopProduct) {
			$this->products[] = $shopProduct;
		}

		abstract public function write();

	}
	

	
/*

public function write() {
	$base = " ";
	foreach ($this->products as $shopProduct) {
		$base .= $shopProduct->getTitle() . ": ";
		$base .= $shopProduct->getProducer();
		$base .= $shopProduct->getPrice();
	}
	print $base;

}



*/

?>
