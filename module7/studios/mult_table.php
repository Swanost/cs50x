<?php

// TODO what should $n really be? Replace the 10 with the user-supplied value from the form
$across = htmlspecialchars($_POST['across']);
$down = htmlspecialchars($_POST['down']);
// if we don't have a number, redirect back to the form page

if (empty($across) || empty($down)) {
    header("Location: ./mult_form.php");
    exit;
}

?>

<!DOCTYPE html>
<html>
    <head>
        <title>Your Table is Ready</title>
    </head>
    <body>
        <table>
            <?php for ($i = 0, $sum1 = 1; $i < $down; $i++, $sum1++): ?>
                <tr>
                    <?php for ($h = 0, $sum2 = 1; $h < $across; $h++, $sum2++): ?>
                    <td><?php $sum = $sum1 * $sum2;
                    print("$sum");
                    ?></td> 
                    <?php endfor ?>
                </tr>
            <?php endfor ?>
        </table>
    </body>
</html>