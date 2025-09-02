<?php
session_start();
if (!isset($_SESSION['username'])) {
    header("Location: login.html");
    exit();
}
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Welcome page</title>
    <link rel="stylesheet" href="welcome.css">
</head>

<body>
    <header>
        <nav>
            <div class="img">
                <img src="" alt="User Icon">
            </div>
            <ul>
                <li><a href="home.html">Home</a></li>
                <li><a href="home.html">About</a></li>
                <li><a href="home.html">Contact Us</a></li>
                <li><a href="home.html">Feedback</a></li>
            </ul>
            <div class="btn">
                <button class="logoutBtn"><a href="logout.php">Logout</a></button>
            </div>
        </nav>
    </header>

    <main class="main">
        <h2>Welcome, <?php echo htmlspecialchars($_SESSION['username']); ?></h2>
        <p>You have successfully logged in.</p>
        
    </main>

</body>

</html>