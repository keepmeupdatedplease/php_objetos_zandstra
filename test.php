<?php
	require 'ShopProduct.class.inc';
	
	$product1 = new ShopProduct("La invencion de Morel", "Adolfo Bioy", "Casares", 9.99);
	
	print "author: " . $product1->getProducer() . "\n";
	


?>


<!-- 




echo "<tt><pre>". var_export($product1, TRUE) ."</pre></tt>"; 




-->
