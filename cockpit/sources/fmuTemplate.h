@import url("./ComponentStyle/Lamp.css");
@import url("./ComponentStyle/Button.css");
@import url("./ComponentStyle/Text.css");

body {
    background-image: url('./Images/PageBackground.jpg'); /* My image path */
    background-size: cover;                 /* Ensures the image covers the entire screen */
    background-position: center;            /* Centers the image */
    background-repeat: no-repeat;           /* Prevents repetition */
    background-attachment: fixed;           /* Keeps the background fixed while scrolling */
    display: flex;
    justify-content: center;
    align-items: center;
    width: 100%;                            /* Full viewport height */
    margin: 0;
    padding: 0;
    font-size: clamp(14px, 1.2vw, 18px); /* Base font-size */

}

.RootContainer {
    position: absolute;
    top: 25%;                           /* 50% from the top of the viewport */
    left: 20%;                          /* 50% from the left of the viewport */
    height: 50%;
    width: 60%;                         /* 80% of the page width */
    margin: 0 auto;                     /* Center the container horizontally */
    padding: 0px;                      /* Padding inside the container */
    background-color: rgba(8, 5, 2, 0);    /* Semi-transparent background */
    border-radius: 10px;                /* Rounded corners */

    /* Grid Layout */
    display: grid;
    grid-template-columns: 1fr 1fr 1fr; /* Three columns */
    gap: 10px; /* Adjust spacing between cells */
}

/* LeftPane placement */
.LeftPane { 
    grid-column: 1 / 2;
    display: grid;
    grid-template-rows: 15% 40% 20% 25%; /* Adjusted to sum to 100% */
    gap: 0px;                           /* Reduced gap */
    box-sizing: border-box;
    overflow: hidden;
    border: 0px solid gray;       
    border-radius: 15px;
    background-image: url('Images/CarModel.png');
    background-size: contain;
    background-position: center; 
    background-repeat: no-repeat;
}

.LeftPane .LeftPane-GridItem {
    display: flex;
    justify-content: center;
    align-items: center;
    background-color: rgba(1, 107, 97, 0.95); /* Light transparent background */
    border-radius: 0px;
    color: white;
    font-size: 20px;
    text-align: center;
    padding-left: 15px;
    padding-right: 15px;
    visibility: hidden;
}

/* Hides text, buttons, etc. but keeps the background */
.LeftPane.hide-content * {
    visibility: hidden;
}

/* .LeftPane.show-content * {
    visibility: visible;
} */

.WarningIcon {
    width: 20%;
    height: 50%;
    object-fit: contain;
    height: auto;
    /* margin-top: 15px; */
    /* filter: drop-shadow(0 0 4px rgba(255, 0, 0, 0.7)); */
}

.hide {
    display: none !important;
}



/* MiddlePane placement */
.MiddlePane { 
    grid-column: 2 / 3;
    display: grid;
    grid-template-rows: 15% 75% 10%; /* Adjusted to sum to 100% */
    gap: 0px;
    border-radius: 15px;                           
    box-sizing: border-box;
    overflow: hidden;
}

.MiddlePane .MiddlePane-GridItem {
    display: flex;
    justify-content: center;
    align-items: center;
    background-color: rgba(0, 0, 0, 0); /* Light transparent background */
    border-radius: 0px;
    color: white;
    font-size: 14px;
    text-align: center;
    flex-direction: column;      /* Stack children vertically */
}

/* RightPane placement */
.RightPane { 
    grid-column: 3 / 4;
    display: grid;
    grid-template-rows: 15% 75% 10%; /* Adjusted to sum to 100% */
    gap: 0px;
    border-radius: 15px;                           
    box-sizing: border-box;
    overflow: hidden;
}

.RightPane .RightPane-GridItem {
    display: flex;
    justify-content: center;
    align-items: center;
    background-color: rgba(0, 0, 0, 0); /* Light transparent background */
    border-radius: 0px;
    color: white;
    font-size: 14px;
    text-align: center;
    flex-direction: column;      /* Stack children vertically */
}

h1, p {
    color: white;
    font-family: Arial, sans-serif;
}

.HighlightText.warning-message {
    color: rgba(204, 163, 0);
    font-family: 'Poppins', sans-serif;
    font-size: clamp(0.5rem, 1.75vw, 1.5rem);
    font-weight: bold;
    text-align: center;
}

.acknowledge-message {
    color: black;
    background-color: rgba(255, 255, 255, 0.85);
    border-radius: 0.5em;
    font-family: 'Poppins', sans-serif;
    font-size: clamp(0.5rem, 1vw, 1.5rem);
    padding: 0.5em 0.75em;
    text-align: center;
    width: 90%;
    max-width: 600px;
    margin: 0 auto;
    box-sizing: border-box;
}

.message-box {
    position: absolute;
    /* object-fit: contain; */
    bottom: 2%;
    left: 50%;
    transform: translateX(-50%);
    width: 90%;
    max-width: 600px; 
    padding: 0.75rem 1.25rem;
    background-color: rgba(255, 255, 255, 0.85);
    color: black;
    font-family: 'Poppins', sans-serif;
    font-size: clamp(0.5rem, 1vw, 1.5rem);
    font-weight: 500;
    border-radius: 0.5em;
    box-shadow: 0 4px 10px rgba(0,0,0,0.2);
    text-align: center;
    z-index: 10;
    box-sizing: border-box;
  }

