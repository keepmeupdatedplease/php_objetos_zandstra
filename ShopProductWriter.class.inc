<?php
	class ShopProductWriter {
		public $products = array();
		
		public function addProduct (ShopProduct $shopProduct) {
			$this->products[] = $shopProduct;
		}

		public function write() {
			$base = " ";
			foreach ($this->products as $shopProduct) {
				$base .= $shopProduct->getTitle() . ": ";
				$base .= $shopProduct->getProducer();
				$base .= $shopProduct->getPrice();
			}
			print $base;

		}


	}

	
?>