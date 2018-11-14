<!DOCTYPE html>
<html lang="en">
<head>
  <title>Bootstrap Example</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  <style>
  .carousel-inner > .item > img,
  .carousel-inner > .item > a > img {
      width: 70%;
      margin: auto;
  }
  </style>
</head>
<body>

<div class="container">
  <br>
  <div id="myCarousel" class="carousel slide" data-ride="carousel">
    <!-- Indicators -->
    <ol class="carousel-indicators">
      <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
      <li data-target="#myCarousel" data-slide-to="1"></li>
      <li data-target="#myCarousel" data-slide-to="2"></li>
      <li data-target="#myCarousel" data-slide-to="3"></li>
    </ol>

    <!-- Wrapper for slides -->
    <div class="carousel-inner" role="listbox">

      <div class="item active">
        <img src="http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/login&register/picture/tiger.jpg" alt="Mizzou tiger" width="460" height="345">
        <div class="carousel-caption">
          <h3>Chania</h3>
          <p>Mizzou Tiger.</p>
        </div>
      </div>

      <div class="item">
        <img src="http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/login&register/picture/Airplane1.jpg" alt="Airplane" width="460" height="345">
        <div class="carousel-caption">
          <h3>Airplane</h3>
          <p>Airplane.</p>
        </div>
      </div>
    
      <div class="item">
        <img src="http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/login&register/picture/Airplane2.jpg" alt="Airplane" width="460" height="345">
        <div class="carousel-caption">
          <h3>Airplane</h3>
          <p>Airplane.</p>
        </div>
      </div>

      <div class="item">
        <img src="http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/login&register/picture/Airplane3.jpg" alt="Airplane" width="460" height="345">
        <div class="carousel-caption">
          <h3>Airplane</h3>
          <p>Airplane.</p>
        </div>
      </div>
  
    </div>

    <!-- Left and right controls -->
    <a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
      <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
      <span class="sr-only">Previous</span>
    </a>
    <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
      <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
      <span class="sr-only">Next</span>
    </a>
  </div>
    <div><a href="http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/login&register/customer_login.php">Customer</a></div>
    <div><a href="http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/login&register/employee_login.php">Employee</a></div>
</div>

</body>
</html>
