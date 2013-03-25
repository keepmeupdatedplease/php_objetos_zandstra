<?php
	class ShopProductWriter {
		
		public function write (ShopProduct $shopProduct) {
			$str = "{$shopProduct->title}, ";
			$str .= $shopProduct->getProducer();
			$str .= " ({$shopProduct->price})";
			print $str;
		}
		
		
	}

	
?>