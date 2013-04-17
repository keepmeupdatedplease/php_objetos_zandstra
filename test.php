<?php
	require_once 'Products/ShopProduct.class.inc';
	require_once 'Products/ShopProductWriter.class.inc';
	require_once 'Products/TextProductWriter.class.inc';
//	require_once 'Products/XmlProductWriter.class.inc'; // comento esta linea a propsito para hacer uso de __autoload()
	require_once("DB.php");	


	function __autoload ($classname) {
		$path = str_replace('_', DIRECTORY_SEPARATOR, $classname);
		
		$path = "./".$path.".class.inc";
		require_once $path;
	}
	
	$db = DB::connect("mysql://root:root@localhost:8889/store");
	$obj = Products_ShopProduct::getInstance(4, $db);
	
	$writer = new Products_XmlProductWriter();


	
	$writer->addProduct($obj);
	$writer->write();
	


	$prod_class = new ReflectionClass('Products_XmlProductWriter');
	Reflection::export($prod_class);



	function classData(ReflectionClass $class) {
		$details = "";
		$name = $class->getName();

		if ($class->isUserDefined()) {
			$details .= "$name is user defined\n";
		}

		if ($class->isInternal()) {
			$details .= "$name is built-in\n";
		}

		if ($class->isInterface()) {
			$details .= "$name is interface\n";
		}

		if ($class->isAbstract()) {
			$details .= "$name is abstract\n";
		}

		if ($class->isFinal()) {
			$details .= "$name is final\n";
		}

		if ($class->isInstantiable()) {
			$details .= "$name can be instantiated\n";
		}else{
			$details .= "$name can not be instantiated\n";	
		}
		return $details;
	}

	
	
/**----

$cd = new CdProduct("Los twists", "Los", "Twists", "10.99", "1:20:00");

$libro = new BookProduct ("La invencion de Morel", "Adolfo", "Bioy Casares", "9.99", "1200 paginas");

	print "author: " . $product1->getProducer() . "\n";

	echo "<tt><pre>". var_export($product1, TRUE) ."</pre></tt>"; 


$product1 = new ShopProduct("La invencion de Morel", "Adolfo Bioy", "Casares", 9.99);


$writer = new ShopProductWriter(); // ahora que es abstracto no es posible instanciarlo
$writer->write($product1);



$libro_rayuela = new BookProduct("Rayuela", null, null, "19.99", null, "1200 paginas");


$clase_write = new ShopProductWriter();
$clase_write->addProduct($libro_rayuela);
$clase_write->write();
echo "<br>";

**/




?>

