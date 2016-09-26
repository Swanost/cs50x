<!--$ php takeout-->
<!--How many orders? 3-->
<!--Order 0 name: Danny-->
<!--Order 0 order: Beef with Broccoli-->
<!--Order 1 name: Tom-->
<!--Order 1 order: Pineapple Fried Rice-->
<!--Order 2 name: Greg-->
<!--Order 2 order: Sesame Chicken, LIKE ALWAYS-->

<!--Total order:-->
<!--Danny: Beef with Broccoli-->
<!--Tom: Pineapple Fried Rice-->
<!--Greg: Sesame Chicken, LIKE ALWAYS-->

<?php
    $number = readline("How many orders? ");
    $totalorder = [];
    for ($counter = 0; $counter < $number; $counter++) {
        $name = readline("Order {$counter} name: ");
        $totalorder[$name] = readline("Order {$counter} order: ");
    }
    
    print("Total Order: \n");
    foreach($totalorder as $key => $value) {
    print("{$key}: {$value}\n");
    }
?>
