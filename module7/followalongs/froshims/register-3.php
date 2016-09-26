<?php
/*
   Filename: register-3.php
   Save in Folder: ~/workspace/module7/followalongs/froshims

   PHP
      // require PHPMailer
      Require "libphp-phpmailer/class.phpmailer.php"

      // validate submission
      If ( !empty($_POST["name"]) AND !empty($_POST["comfort"]) && !empty($_POST["dorm"]))
      {
          // instantiate mailer
          Declare a variable called mail and create an instance of the PHPMailer class  
          // Hint: $instance = new Class();

          // configure mailer use SMTP
          Call the method IsSMTP() 
          // Hint: $instance->Method();

          Set member variable Host to "smtp.gmail.com"
          // Hint: $instance->Member_Variable = "smtp.gmail.com";
          Set member variable Password to "crimson50"
          Set member variable Port to "587"
          Set member variable SMTPAuth to true
          Set member variable SMTPSecure to "tls"
          Set member variable Username to "jharvard@cs50.net"

          // set From:
          Call the method SetFrom("jharvard@cs50.net");

          // set To:
          Call the method AddAddress("jharvard@cs50.net");

          // set Subject:
          Set member variable Subject to "registration"

          // set body
          Set member variable Body to  
              "This person just registered:\n\n" .
              "Name: " . $_POST["name"] . "\n" .
              "Captain: " . $_POST["captain"] . "\n" .
              "Comfort: " . $_POST["comfort"] . "\n" .
              "Dorm: " . $_POST["dorm"]

          // send mail
          IF ($mail->Send() == false)
          {
              Print $mail->ErrInfo
              exit;
          }
      }
      else
      {
          Header "Location: froshims-3.php"
          exit;
      }
    PHP

   DOCTYPE declaration

   HTML 
      Head
          Title Frosh IMs Title
      Head
      Body 
        You are registered! (Really.)
      Body
   HTML 
*/
?>