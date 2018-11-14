<!DOCTYPE html>
<html>

<head>
  <title>Employee Profile</title>
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">
  <link rel="stylesheet" href="style.css">
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
</head>

<body>
<div id="pagewrapper">

<!-- Code for the NavBar -->
<nav class="navbar navbar-inverse navbar-fixed-top js-nav">
  <div class="container">
    <div class="container-fluid">
      <div class="navbar-header">
        <a class="navbar-brand" href="">Missouri Airlines</a>
      </div>
      <ul class="nav navbar-nav">
        <li><a href="">Flying With MO Airlines</a></li>
        <li><a href="">Plan A Trip</a></li>
      </ul>
      <ul class="nav navbar-nav navbar-right">
        <li><a href="profile.php"><span class ="glyphicon glyphicon-user"></span> Profile</a></li>
        <li><a href=""><span class="glyphicon glyphicon-log-in"></span> Logout</a></li>
      </ul>
    </div>
  </div>
</nav>



<!-- Code for the content -->
<div class="container">
  <div class="jumbotron">
    <h4>Employee Information</h4>
    <p>John Smith</p>
  </div>
  <div class="content">
    <div class="col-md-7 emp_info" style="background-color:#eee;">
      <form method="POST">
      <p><strong>Position: </strong> Junior Pilot</h2>
      <p><strong>Date of Birth: </strong> 04/16/1983 </p>
      <p><strong>Phone Number: </strong> 636-442-9873 </p>
      <p><strong>SSN: </strong> ***-***-xxxx</p>
      <p><strong>Employee Number: </strong> 158345983 </p>
      <form>
      <div class="action">
        <form method ="POST">
        <input class="btn btn-primary" type="submit" name="edit" value="Edit Information">
        <input class="btn btn-primary" type="submit" name="flights" value="View Flights">
        <form>
      </div>
    </div>
    <div class="col-md-1"></div>
    <div class="col-md-4 emp_pic" style="background-color:#eee;">
      <h2>Employee Picture</h2>
      <img src="https://www.outsystems.com/PortalTheme/img/UserImage.png?24860"><img>
    </div>
  </div>
</div>



<div class="container">
  <hr>
    <div class="content" style="text-align:center;">
      <div class="col-sm-6">About</div>
      <div class="col-sm-6">Customer Service</div>
    </div>
  </div>

</body>
</html>
