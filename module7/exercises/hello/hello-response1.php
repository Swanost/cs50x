<?php 

$username = $_GET["username"]; 
// TODO we also need to grab the greeting field that the user typed into the form
$greeting = $_GET["greeting"];

if (empty($username) || empty($greeting)): // TODO we also want to check if the greeting is an empty value

    // redirect the user back to the index page
    header("Location: ./hello-form1.php"); // notice we can use a "relative" link here

    // stop running this script
    exit;
endif

?>

<!DOCTYPE html>
<head>
</head>
<body>
    <?php print("$greeting, $username"); ?>!
    <!-- TODO replace the hard-coded "Hello" above with the user-supplied greeting -->
</body>