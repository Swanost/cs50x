<?php 

$username = $_GET["username"]; 
$greeting = $_GET["greeting"]; 

?>

<!DOCTYPE html>
<head>
</head>
<body>
    <!-- TODO replace "false" below with a condition to check if either value is empty (same condition as last time) -->
    <?php if (empty($username) || empty($greeting)): ?> 
        <!-- TODO Yell at the user and provide a link back to the form -->
        Please fill in all fields <a href="./hello-form2.php">here.</a>
    <?php else: ?>
        <!-- TODO greet the user just like last time -->
        <?php print("$greeting, $username") ?>!
    <?php endif ?>
</body>