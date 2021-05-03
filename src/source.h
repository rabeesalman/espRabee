#include <Arduino.h>
char test[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="ar">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, user-scalable=no" />
    <title>espRabee</title>
    <style>
        body {
            padding: 0px;
            top: 5px;
            text-align: center;
            background-color: #cacaca;
        }

        .container {
            width: 360px;
            height: 100%;
            display: inline-block;
            text-align: center;
            border-radius: 5px;
            background: #5c5c5c;
            box-shadow: 6px 6px 12px #19191a,
                -4px -4px 4px #ffffff;
        }

        .topsection {
            display: inline-block;
            position: relative;
            width: 340px;
            height: 110px;
            border-radius: 5px;
        }

        @keyframes fanrotate {
            0% {
                transform: rotate(0deg);
            }

            100% {
                transform: rotate(360deg);
            }
        }

        #fanpath {
            transform-origin: 100px 100px;
            color: rgb(21, 255, 0);
            animation-name: fanrotate;
            animation-duration: 2s;
            animation-iteration-count: infinite;
            animation-timing-function: linear;
        }

        .fan,
        .power,
        .door,
        .lamp,
        .water,
        #egg {
            width: 75px;
            height: 70px;
            top: 13px;
            margin-right: 11px;
            margin-left: 11px;
            position: relative;
            display: inline-block;
            color: yellow;
            padding: 3px 6px 10px 4px;
            border-radius: 5px;
            background: #2c2c2c;
            box-shadow: 6px 6px 12px #000000,
                -4px -4px 8px #aaaaaa;
        }

        .lamp {
            animation-name: lampoff;
            animation-duration: 1s;
            animation-iteration-count: 1;
            animation-timing-function: ease-in;
            animation-fill-mode: both;
        }

        @keyframes lampon {
            0% {
                color: #31343b;
            }

            100% {
                color: #fcfc01;
            }
        }

        @keyframes lampoff {
            0% {
                color: #fcfc01;
            }

            100% {
                color: #31343b;
            }
        }

        .eggrotate {
            transform-origin: 620px 900px;
            animation-name: eggright;
            animation-duration: 3s;
            animation-iteration-count: 1;
            animation-timing-function: ease-in-out;
            animation-fill-mode: both;
        }

        @keyframes eggleft {
            0% {
                transform: rotate(90deg);
            }

            100% {
                transform: rotate(-90deg);
            }
        }

        @keyframes eggright {
            0% {
                transform: rotate(-90deg);
            }

            100% {
                transform: rotate(90deg);
            }
        }

        .meters {
            background: linear-gradient(180deg, #464646, #d3d1d1, #666666, #cacaca, #464646);
            height: inherit;
            border-radius: 15px;
            width: 90%;
            position: relative;
            left: 18px;
        }

        .thermometerRed_base {
            top: 5px;
            display: inline-block;
            position: relative;
            width: 95%;
            height: 3em;
            border-radius: 5px;
        }

        .thermometerRed_liquid {
            z-index: 1;
            position: absolute;
            transition: 1s ease-in-out;
            display: inline-block;
            top: 25%;
            width: 100%;
            height: 50%;
            border-radius: 10px 0px 0px 10px;
            background-color: rgb(173, 0, 0);
            box-shadow: -1px -1px 1px -1px rgba(216, 215, 215, 0.247)inset, 4px 4px 5px 1px rgba(85, 1, 1, 0.986)inset, 3px 4px 10px -3px rgb(255, 0, 0), 0px 7px 0.1px 0px rgba(255, 255, 255, 0.616)inset;
        }

        .temptxt {
            z-index: 1;
            position: absolute;
            text-align: right;
            top: 12px;
            right: 2%;
            color: rgb(0, 0, 0);
            font-weight: bold;
            font-family: 'Times New Roman', Times, serif;
            font-size: 4.3vmin;
            background: transparent;
        }

        .Redtube {
            z-index: 0;
            transform: translateY(50%);
            display: inline-block;
            position: relative;
            width: 100%;
            height: 50%;
            border-radius: 10px 10px 10px 10px;
            background-color: transparent;
            box-shadow: -1px -1px 1px -1px rgba(216, 215, 215, 0.247)inset, 4px 4px 5px 1px rgba(83, 82, 82, 0.651)inset, 3px 4px 10px -3px rgb(199, 197, 197), 0px 7px 0.1px 0px rgba(255, 255, 255, 0.616)inset;
            /* box-shadow: 3px -3px 3.5px -1px rgb(255, 255, 255)inset, 0px 3px 6px 0.5px rgba(0, 0, 0, 0.603)inset, -3px 5px 12px 0.1px rgb(95, 95, 97); */
        }

        .thermometerBlue_base {
            top: 10px;
            position: relative;
            display: inline-block;
            width: 95%;
            height: 3em;
            border-radius: 5px;
        }

        .thermometerBlue_liquid {
            z-index: 1;
            position: absolute;
            transition: 1s ease-in-out;
            display: inline-block;
            top: 25%;
            width: 100%;
            height: 50%;
            border-radius: 10px 0px 0px 10px;
            background-color: rgb(0, 110, 255);
            box-shadow: -1px -1px 1px -1px rgba(216, 215, 215, 0.247)inset, 4px 4px 5px 1px rgb(0, 40, 170)inset, 3px 4px 10px -3px rgb(0, 162, 255), 0px 7px 0.1px 0px rgba(255, 255, 255, 0.616)inset;
        }

        .humtxt {
            z-index: 1;
            position: absolute;
            text-align: right;
            top: 12px;
            right: 2%;
            color: rgb(0, 0, 0);
            font-weight: bold;
            font-family: 'Times New Roman', Times, serif;
            font-size: 4.3vmin;
            background: transparent;
        }

        .tube {
            z-index: 0;
            transform: translateY(50%);
            display: inline-block;
            position: relative;
            width: 100%;
            height: 50%;
            border-radius: 10px 10px 10px 10px;
            background-color: transparent;
            box-shadow: -1px -1px 1px -1px rgba(216, 215, 215, 0.247)inset, 4px 4px 5px 1px rgba(83, 82, 82, 0.651)inset, 3px 4px 10px -3px rgb(199, 197, 197), 0px 7px 0.1px 0px rgba(255, 255, 255, 0.616)inset;
        }

        .turningbase {

            border: 1px solid black;
            border-radius: 5px;
            text-align: center;
            font-weight: 600;
            font-family: 'Times New Roman', Times, serif;
            display: inline-block;
            font-size: 3.5vmin;
            overflow: hidden;
            position: relative;
            height: 25px;
            width: 300px;
            background-color: rgb(143, 143, 143);
        }

        .turninglevel {
            z-index: 1;
            position: absolute;
            width: 100%;
            transition: 1s ease-in-out;
            height: inherit;
            border-radius: 0.4rem 0rem 0rem 0.4rem;
            background-color: rgb(206, 205, 205);
        }

        .turningtxt {
            z-index: 2;
            position: relative;
            width: 100%;
            height: 30px;
            background-color: transparent;
        }

        #aa,
        #bb,
        #cc,
        #dd,
        #ee,
        #ff,
        #gg,
        #hh,
        #ii,
        #jj {
            list-style: none;
            left: -20px;
            line-height: 20px;
            text-align: right;
            top: -15px;
            text-decoration: none;
            position: relative;
            width: 300px;
            border-radius: 0px;
            text-size-adjust: inherit;
            color: rgb(255, 255, 255);
            background: #434443;
        }

        .setting {
            top: -20px;
            padding-bottom: -10px;
            width: 90%;
            height: 35px;
            position: relative;
            cursor: pointer;
            text-align: center;
            font-weight: bold;
            font-family: 'Times New Roman', Times, serif;
            font-size: 1.3rem;
            border-radius: 5px;
            background: linear-gradient(90deg, #7c7a7a, #bdbbbb, #7c7a7a);
            box-shadow: 4px 4px 3px #0c0c0c,
                -4px -4px 3px #24232313;
        }

        .setting_list {
            visibility: hidden;
            width: 360px;
            /* left: calc(50% - 180px); */
            color: rgb(255, 255, 255);
            text-align: inherit;
            font-size: 1.2rem;
            position: absolute;
            top: -400px;
            left: -10px;
        }

        .slist {
            list-style: none;
            padding-left: 0px;
        }

        li {
            position: relative;
            top: 0px;
            line-height: 2;
            border-radius: 8px;
            background: linear-gradient(180deg, #383737, #141414);
        }

        #f {
            background-color: rgb(71, 72, 75);
        }

        .show {

            visibility: visible;

        }

        .undo {

            position: relative;
            font-family: 'Times New Roman', Times, serif;
            font-size: 25px;
            color: rgb(255, 255, 255);
            border-radius: 0.4rem 0.4rem;
            height: 40px;
            width: inherit;
            line-height: 40px;
            text-indent: 160px;
            border-radius: 15px;
            background: #02b964;
            box-shadow: inset -4px -4px 8px #01610e,
                inset 4px 4px 8px #00ee5b;

        }

        .save {
            position: absolute;
            left: 0px;
            font-size: 25px;
            top: 0px;
            height: inherit;
            width: 100px;
            border-radius: 15px 0px 0px 15px;
            background: #700202;
            line-height: 45px;
            text-indent: 10px;
            color: rgb(255, 255, 255);
            box-shadow: inset -4px -4px 8px #030101a1,
                inset 2px 2px 9px #fffdfd;

        }

        .field,
        .lowTempAlarm,
        .hTempAlarm,
        .hihumidityAlarm,
        .lowhumidityAlarm,
        .turningtime,
        .hatching {
            display: inline-block;
            position: relative;
            text-decoration: none;
            width: 380px;
            height: 30px;

        }

        #setTmp_minval,
        #setTmp_maxval,
        #hTempAlarm_minval,
        #hTempAlarm_maxval,
        #lowTempAlarm_minval,
        #lowTempAlarm_maxval,
        #hihumidityAlarm_minval,
        #hihumidityAlarm_maxval,
        #lowhumidityAlarm_minval,
        #lowhumidityAlarm_maxval,
        #turningtime_minval,
        #turningtime_maxval,
        #hatching_minval,
        #hatching_maxval {
            display: inline-block;
            width: auto;
            height: auto;
            position: relative;
            font-size: 16px;
        }

        .slidevalue {
            position: relative;
            display: inline-block;
            width: 20px;
            text-align: center;

        }

        .turningset {
            text-align: center;
            font-size: inherit;
            margin-bottom: 3px;
            border-radius: 5px;
            background: #b80101;
            box-shadow: 0px 0px 3px 3px #ff0000;
        }

        #birthday {

            font-size: 18px;

        }
    </style>

<body>
    <div class="container">

        <div class="topsection">

            <svg class="fan" width="75px" height="75px" viewBox="-35 -55 270 270">

                <path id="fanpath" fill="currentColor" d="m51.002 0c-10.745 0-21.362 4.7013-29.9 
                13.236-20.372 20.38-20.129 53.77 0.53515 
                74.432 12.474 12.479 32.972 20.881 51.222 
                21.086-2.1824 2.978-4.8504 5.5997-8.707 
                6.959-5.3912 1.9027-11.048 1.0129-17.115-0.33008-3.9968-0.8802-8.1328-1.7949-12.775-1.7949-6.207 0-12.022 1.6996-17.771 
                5.1953-8.863 5.391-14.926 15.031-16.221 25.791-1.4764 12.294 
                3.1326 24.489 12.973 34.33 9.7695 9.771 22.814 15.148 36.726 
                15.148 14.197 0 27.586-5.5686 37.699-15.68 12.64-12.642 
                20.864-32.798 21.008-51.283 3.0056 2.1886 5.669 4.8717 7.039 8.7598 
                2.1166 6.015 0.98174 11.158-0.33203 17.115-1.8009 8.1576-4.0391 
                18.312 3.4004 30.551 6.1833 10.167 17.761 16.484 30.217 16.484 10.745 
                0 21.362-4.702 29.9-13.236 20.368-20.376 20.13-53.766-0.53516-74.432-12.474-12.48-32.974-20.88-51.222-21.084
                 2.1804-2.9794 4.8498-5.6036 8.705-6.9629 5.4-1.8952 11.056-0.99877 
                 17.113 0.33203 3.9982 0.88088 8.1355 1.7949 12.775 1.7949 6.2097 
                 0 12.023-1.7015 17.773-5.1973 8.863-5.3896 14.926-15.03 16.221-25.789 
                 1.4757-12.294-3.1299-24.49-12.973-34.332-9.7702-9.771-22.812-15.148-36.724-15.148-14.198 0-27.587 
                 5.5698-37.701 15.682-12.64 12.642-20.863 32.798-21.006 51.283-3.0076-2.1893-5.6711-4.8723-7.039-8.7617-2.1173-6.0151-0.98233-11.159 
                 0.33008-17.115 1.8009-8.1583 4.0384-18.312-3.4004-30.551-6.1833-10.165-17.759-16.482-30.215-16.482zm48.998 87.932c3.2258 0 6.2552 
                 1.2544 8.5351 3.5332 4.7028 4.708 4.7035 12.362 0 17.07-4.5578 4.5582-12.512 
                 4.5582-17.07 0-4.7042-4.708-4.7042-12.362 0-17.07 2.2786-2.2788 5.31-3.5332 
                 8.5351-3.5332z" />

            </svg>

            <svg class="power" fill="currentColor" viewBox="0 -10 65 75" width="85px" height="85px">

                <path
                    d="M 59,12 H 56 V 11 A 3,3 0 0 0 53,8 V 3 A 1,1 0 0 0 52,2 h -6 a 1,1 0 0 0 -1,1 v 5 a 3,3 0 0 0 -3,3 v 1 H 22 V 11 A 3,3 0 0 0 19,8 V 3 A 1,1 0 0 0 18,2 h -6 a 1,1 0 0 0 -1,1 v 5 a 3,3 0 0 0 -3,3 v 1 H 5 a 3,3 0 0 0 -3,3 v 8 a 3,3 0 0 0 2,2.816 V 59 a 3,3 0 0 0 3,3 h 50 a 3,3 0 0 0 3,-3 V 25.816 A 3,3 0 0 0 62,23 V 15 A 3,3 0 0 0 59,12 Z M 47,4 h 4 v 4 h -4 z m -3,7 a 1,1 0 0 1 1,-1 h 8 a 1,1 0 0 1 1,1 v 1 H 44 Z M 13,4 h 4 v 4 h -4 z m -3,7 a 1,1 0 0 1 1,-1 h 8 a 1,1 0 0 1 1,1 v 1 H 10 Z m 48,48 a 1,1 0 0 1 -1,1 H 7 A 1,1 0 0 1 6,59 V 26 h 52 z m 2,-36 a 1,1 0 0 1 -1,1 H 5 A 1,1 0 0 1 4,23 v -8 a 1,1 0 0 1 1,-1 h 54 a 1,1 0 0 1 1,1 z"
                    id="path2" />
                <path
                    d="m 11,46 h 4 v 4 a 1,1 0 0 0 1,1 h 4 a 1,1 0 0 0 1,-1 v -4 h 4 a 1,1 0 0 0 1,-1 v -4 a 1,1 0 0 0 -1,-1 h -4 v -4 a 1,1 0 0 0 -1,-1 h -4 a 1,1 0 0 0 -1,1 v 4 h -4 a 1,1 0 0 0 -1,1 v 4 a 1,1 0 0 0 1,1 z m 1,-4 h 4 a 1,1 0 0 0 1,-1 v -4 h 2 v 4 a 1,1 0 0 0 1,1 h 4 v 2 h -4 a 1,1 0 0 0 -1,1 v 4 h -2 v -4 a 1,1 0 0 0 -1,-1 h -4 z"
                    id="path4" />
                <path
                    d="m 39,46 h 14 a 1,1 0 0 0 1,-1 V 41 A 1,1 0 0 0 53,40 H 39 a 1,1 0 0 0 -1,1 v 4 a 1,1 0 0 0 1,1 z m 1,-4 h 12 v 2 H 40 Z"
                    id="path6" />

            </svg>

            <svg class="door" viewBox="5 -19 100 109" width="85px" height="85px" fill="currentColor">
                <path
                    d="m 44.938957,52.81724 c 0.553209,-0.956194 0.479289,-2.186608 -0.205069,-3.3741 L 25.471708,16.081273 c -0.684358,-1.185108 -1.712087,-1.864698 -2.818506,-1.864698 -1.106418,0 -2.131764,0.67959 -2.816122,1.864698 L 0.57251565,49.44314 c -0.68435821,1.185108 -0.75827844,2.415522 -0.20506901,3.371716 0.55320943,0.958578 1.65485926,1.509403 3.02357576,1.509403 H 41.917766 c 1.368716,0 2.467981,-0.550825 3.021191,-1.507019 z M 22.653202,49.075923 c -1.383023,0 -2.501365,-1.118341 -2.501365,-2.501365 0,-1.380639 1.120726,-2.501365 2.501365,-2.501365 1.380638,0 2.501364,1.120726 2.501364,2.501365 0,1.383024 -1.120726,2.501365 -2.501364,2.501365 z M 24.76112,40.556021 H 20.547668 L 20.151837,25.023235 h 5.002729 z" />
                <path
                    d="M 99.13202,0.546103 C 98.700421,0.193193 98.163904,0.004816 97.615463,0.0072 97.615463,0.0048 35.61547,0 35.61547,0 34.299214,0 33.230947,1.068266 33.230947,2.384523 V 19.98469 l 4.769047,8.25999 V 4.771431 h 34.8975 L 54.305365,8.393522 c -1.120726,0.219376 -1.92908,1.199416 -1.92908,2.339218 V 77.399292 H 37.999994 V 59.093306 h -4.769047 v 20.690509 c 0,1.318642 1.068267,2.384524 2.384523,2.384524 h 16.760815 v 6.459674 c 0,0.712972 0.317142,1.385408 0.867967,1.838467 0.431599,0.35291 0.968116,0.546056 1.516557,0.546056 0.152609,0 0.302834,-0.01431 0.455444,-0.04531 l 42.854654,-8.345832 c 1.120726,-0.219376 1.92908,-1.199415 1.92908,-2.339217 V 2.386951 C 100.00239,1.673978 99.682845,0.999158 99.13202,0.546099 Z M 62.794268,56.515636 c -2.112688,0 -3.824775,-2.95204 -3.824775,-6.597976 0,-3.645937 1.712087,-6.597976 3.824775,-6.597976 2.110303,0 3.822391,2.952039 3.822391,6.597976 0,3.645936 -1.712088,6.597976 -3.822391,6.597976 z" />
            </svg>

        </div>

        <hr style="height:2px;border-width:0;color:gray;background-color:gray;width: 80%;">

        <div class="topsection">

            <svg class="lamp" width="85px" height="85px" viewBox="0 -15 100 125" fill="currentColor">
                <path
                    d="m 49.971051,2.2263821e-4 c -1.020892,0 -1.833778,0.84743900179 -1.819297,1.85839096179 v 7.33332 
        c -0.0273,1.0310654 0.807189,1.8798784 1.848239,1.8798974 1.041043,0 1.879153,-0.848832 1.851856,-1.8798974 
        v -7.33332 C 51.866549,0.82549664 51.014236,-0.01570936 49.971051,2.2263821e-4 Z 
        M 82.878832,14.346798 77.477573,19.705129 c -0.716501,0.716464 -0.713295,1.871569 0.0077,2.585282 0.720203,
        0.713 1.887531,0.716471 2.611401,0 l 5.233652,-5.184894 
        c 1.208371,-1.165478 0.340157,-3.191677 -1.345575,-3.143956 -0.48077,-9.1e-5 -0.938016,0.211803 -1.105631,
        0.385239 z m -68.205073,2.7658 5.233644,5.184873 
        c 0.723947,0.708857 1.887762,0.706092 2.607783,0 0.720035,-0.712999 0.723422,-1.868804 0.0077,
        -2.585268 L 17.28922,14.530884 c -0.419177,-0.318725 -0.887866,-0.548073 -1.327475,-0.560378 -1.661115,-0.0055 
        -2.478837,1.995323 -1.287705,3.142092 z m 35.326233,1.213864 
        c -17.350977,0 -31.456123,13.96955 -31.456158,31.155861 0.0112,9.81717 4.717424,19.026295 12.633832,24.893164 
        l 5.067255,13.628242 H 63.736982 L 68.688498,74.461435 C 76.680646,68.604239 81.440869,59.354233 81.456169,
        49.482323 81.456127,32.295333 67.350959,18.326462 49.999992,18.326462 Z M 1.8916296,47.681202
        C 0.85446293,47.681202 0,48.486956 0,49.514537
        c 0,1.027594 0.85446293,1.851939 1.8916296,1.829752 h 7.4001878 c 1.0371656,0 1.8880136,-0.802158 
        1.8880136,-1.829752 0,-1.027581 -0.850848,-1.854801 -1.8880136,-1.833335 z m 88.8165564,0 c -1.037165,
        0 -1.888021,0.805754 -1.888021,1.833335 0,1.027594 0.850856,1.851939 1.888021,1.829752 h 7.403793 
        c 1.037165,0 1.888021,-0.802158 1.888021,-1.829752 0,-1.027581 -0.850856,-1.854801 -1.888021,-1.833335 z 
        M 37.047888,91.666698 v 7.319001 h 25.904219 v -7.319001 z m 0.705295,10.985662 3.190089,6.33071 C 41.256483,
        109.60669 41.898163,110 42.599811,110 h 14.803961 c 0.701004,0 1.340017,-0.39676 1.652927,-1.01693 l 3.193725,-6.33071 z" />
            </svg>

            <svg class="water" viewBox="0 -20 100 170" fill="currentColor" width="85px" height="85px">

                <path d="m 26.62115,103.54115 c 3.750462,6.78643 7.655802,13.18602
                    10.683809,20.21717 15.047292,34.93177 -49.961647,35.01171
                    -35.0720153,0.10268 3.108692,-7.28674 7.126249,-13.51166
                    10.9230823,-20.32079 H 26.62115 Z m -4.104734,12.27221
                    c 2.541114,4.09239 5.656298,8.73837 7.06133,13.39522
                    1.365153,4.5256 0.558303,8.78475 -6.163594,11.0811 
                    -1.224186,0.41743 -1.896561,1.81084 -1.505193,3.11345
                    0.393224,1.30162 1.70366,2.01905 2.926919,1.60162 
                    10.177441,-3.47561 11.330217,-10.16039 9.173979,
                    -17.30898 -1.572894,-5.21638 -4.782674,-10.06762
                    -7.608504,-14.6179 -1.689749,-2.71674 -5.573758,0.0198
                    -3.884937,2.73549 z M 67.385632,29.861538 c 0,-7.935092 
                    0.745641,-16.50274 -7.915478,-16.919182 0,-1.551295 0,
                    -3.1025893 0,-4.6538846 4.096387,0 8.192775,0 12.290086,
                    0 2.96866,3.9917216 9.67664,2.7680546 9.58297,-3.0236446 -0.089,
                    -5.46209767 -6.28786,-6.7824755 -9.58297,-3.1075237 -10.137558,
                    0 -20.274193,0 -30.411756,0 -3.531592,-3.9453428 -9.706315,
                    -2.24306207 -9.648815,3.1854835 0.05472,5.1877594 6.260044,7.0518794 
                    9.648815,2.9466711 3.865462,0 7.729996,0 11.59453,0 0,1.5512954 
                    0,3.1025903 0,4.6538853 -7.720722,0 -7.220845,9.12126 -7.220845,16.919183 
                    7.221772,-9.88e-4 14.442618,-9.88e-4 21.663463,-9.88e-4 z M 34.89461,98.520166 
                    c 0.03802,-5.396971 0.324595,-8.163051 -5.0711,-8.322916 -0.05194,-7.213722 
                    -0.06956,-7.09925 0,-12.663977 0.04081,-3.253576 0.227217,-5.188747 
                    2.847161,-5.393021 11.127114,19.04777 38.130627,18.174428 46.310419,-0.814134
                    7.70681,0 13.31117,0 21.01891,0 0,-7.683451 0,-15.365914 0,-23.048378 -9.39656,
                    0 -16.69067,0 -26.08723,0 -1.91325,-2.03484 -4.297635,-4.146654 -6.52621,
                    -5.393019 1.943859,0 3.887719,0 5.83158,0 0,-3.077921 0,-6.156826 0,-9.234746
                    -11.085381,0 -22.17076,0 -33.257067,0 0,3.07792 0,6.156825 0,9.234746 1.920674,
                    0 3.842276,0 5.76295,0 -2.381599,1.205905 -3.850622,2.545031 -5.76295,4.58086
                    -0.273587,0.291114 -6.55589,-0.0039 -7.290402,0 C 13.725458,47.585973 9.2377017,
                    62.419 9.5539497,77.836229 c 0.0102,5.69499 0.172499,5.247956 -0.0037,12.361021
                    -5.004326,-0.07991 -5.008035,2.137473 -5.000616,8.322916 z" />
            </svg>

            <svg id="egg" width="85px" height="85px" viewBox="0 0 1276.6526 1677.307"
                enable-background="new 0 0 1276.6526 1677.307">
                <g class="eggrotate">
                    <radialGradient id="SVGID_1_" cx="636.3965" cy="840.0656" r="716.6335"
                        gradientTransform="matrix(0.9758 0 0 1 17.3306 0)" gradientUnits="userSpaceOnUse">
                        <stop offset="0" style="stop-color:#FFFFFF" />
                        <stop offset="0.1006" style="stop-color:#F5E6DD" />
                        <stop offset="0.2424" style="stop-color:#E9C8B3" />
                        <stop offset="0.3875" style="stop-color:#DFAE91" />
                        <stop offset="0.5344" style="stop-color:#D89B76" />
                        <stop offset="0.6837" style="stop-color:#D28D63" />
                        <stop offset="0.8368" style="stop-color:#CF8558" />
                        <stop offset="1" style="stop-color:#CE8254" />
                    </radialGradient>
                    <path fill="url(#SVGID_1_)" d="M638.3279,41.4776c-293.1773,0-620.2347,425.4311-608.6061,872.1713
                   c11.2001,430.3124,282.8846,725.0048,608.6061,725.0048c325.7179,0,597.3976-294.6924,608.6024-725.0048
                   C1258.5682,466.9086,931.5145,41.4776,638.3279,41.4776z" />

                    <radialGradient id="SVGID_2_" cx="636.3965" cy="649.3899" r="779.0441"
                        gradientTransform="matrix(4.381009e-011 -1 0.8134 3.742355e-011 110.1268 1285.7864)"
                        gradientUnits="userSpaceOnUse">
                        <stop offset="0" style="stop-color:#FFFFFF;stop-opacity:0.7" />
                        <stop offset="1" style="stop-color:#FFFFFF;stop-opacity:0" />
                    </radialGradient>
                    <path fill="url(#SVGID_2_)" d="M638.3279,41.4776c-293.1773,0-620.2347,425.4311-608.6061,872.1713
                   c11.2001,430.3124,282.8846,725.0048,608.6061,725.0048c325.7179,0,597.3976-294.6924,608.6024-725.0048
                   C1258.5682,466.9086,931.5145,41.4776,638.3279,41.4776z" />
                    <path display="none" fill="#BB805E"
                        d="M1246.9303,913.6488c0,0-0.0186-9.0485-0.0453-26.0269
                   c0.0629-8.4804,0-18.9626-0.7843-31.2408c-0.6318-12.292-1.0106-26.4288-2.7612-42.1748
                   c-2.2734-31.602-8.11-69.6954-16.7076-112.9077c-8.7954-43.2169-22.2921-91.2115-40.6774-142.2455
                   c-18.5664-50.9259-42.4454-104.8688-73.4432-158.7361c-31.0062-53.7896-67.9496-108.3377-113.2181-158.7764
                   c-22.292-25.4991-46.8935-49.6944-73.2271-72.469c-26.2255-22.9144-54.6608-43.9568-85.1172-62.1755
                   c-60.4612-36.4559-130.4135-62.7165-202.6208-62.5946c-72.2202-0.0998-142.1411,26.1387-202.6023,62.6081
                   c-30.4611,18.2142-58.9102,39.2566-85.1302,62.171c-26.329,22.7655-50.9351,46.9699-73.2225,72.4689
                   c-45.2741,50.4298-82.2165,104.9954-113.2273,158.7675c-30.9978,53.8765-54.8686,107.8102-73.4433,158.7499
                   c-18.3815,51.0201-31.8685,99.0277-40.6734,142.2316c-8.6019,43.2122-14.4388,81.3057-16.7212,112.9077
                   c-1.7501,15.746-2.1155,29.8828-2.756,42.1748c-0.7714,12.2874-0.8525,22.7604-0.7758,31.2408
                   c-0.0361,16.9784-0.0541,26.0269-0.0541,26.0269s-0.0722-9.0485-0.194-26.0269c-0.1488-8.4804-0.1804-18.9626,0.4782-31.2593
                   c0.5232-12.291,0.7578-26.4592,2.3591-42.2468c1.9802-31.6519,7.4562-69.835,15.6566-113.2236
                   c8.3809-43.384,21.4349-91.6752,39.8252-142.8672c18.4527-51.1512,42.2247-105.3335,73.1495-159.4982
                   c30.948-54.0695,67.846-108.9603,113.183-159.8099c22.3142-25.693,46.9748-50.1184,73.3934-73.1274
                   c26.3198-23.1444,54.9093-44.4485,85.5773-62.9198c60.876-36.9739,131.5997-63.908,205.1779-64.0161
                   c73.5883,0.1358,144.2797,27.0422,205.1741,64.0251c30.6727,18.4758,59.2529,39.7753,85.5588,62.9197
                   c26.4417,23.0091,51.0884,47.4255,73.4165,73.1185c45.3323,50.8496,82.2386,105.7403,113.182,159.8099
                   c30.9258,54.1647,54.6885,108.3469,73.1552,159.4982c18.376,51.192,31.4302,99.4832,39.8108,142.8672
                   c8.219,43.3887,13.6859,81.5718,15.662,113.2236c1.5963,15.7876,1.8309,29.9558,2.363,42.2468
                   c0.6494,12.3058,0.6318,22.7789,0.4785,31.2593C1247.0023,904.6003,1246.9303,913.6488,1246.9303,913.6488z" />
                </g>
            </svg>

        </div>

        <hr style="height:2px;border-width:0;color:gray;background-color:gray;width: 80%;">

        <div class="topsection">
            <div class="meters">
                <div class="thermometerRed_base">
                    <div class="thermometerRed_liquid"></div>
                    <div class="Redtube"> </div>
                    <div class="temptxt"></div>
                </div>

                <div class="thermometerBlue_base">
                    <div class="thermometerBlue_liquid"></div>
                    <div class="tube"> </div>
                    <div class="humtxt"></div>
                </div>
            </div>
        </div>

        <hr style="height:2px;border-width:0;color:gray;background-color:gray;width: 80%;">

        <div class="topsection">

            <div class="turningbase">
                <div class="turninglevel"></div>
                <div class="turningtxt"></div>
            </div>

            <div>
                <ul class="txtlist">
                    <li id="aa"> درجة الحرارة المطلوبة *</li>
                    <li id="bb"> انذار عندارتفاع الحرارة عن *</li>
                    <li id="cc"> انذار عند انخفاض الحرارة عن *</li>
                    <li id="dd"> انذار عند ارتفاع الرطوبة عن *</li>
                    <li id="ee"> انذار عند انخفاض الرطوبة عن *</li>
                    <li id="ff"> حالة التقليب *</li>
                    <li id="gg"> عدد مرات التقليب باليوم *</li>
                    <li id="hh"> فترة التفقيس * </li>
                    <li id="ii"> تاريخ وضع البيض *</li>
                    <li id="jj"> الايام المتبقية للتفقيس*</li>
                </ul>
            </div>

            <button type="button" class="setting" onclick="settingFunction()">الضبط</button>

            <div class="setting_list" id="mysetting" style="z-index: 3;">
                <ul class="slist">
                    <li id="a">درجة الحرارة المطلوبة
                        <span id="setTmp_point"></span>
                        <div class="field">
                            <div id="setTmp_minval"></div>
                            <input id="setTmp_slidetemp" oninput="updateTemp_func()" style="width: 70%;" type="range"
                                value="0.0" step="0.1" min="34.0" max="39.0">
                            <div id="setTmp_maxval"></div>

                        </div>
                    </li>
                    <li>انذار عند ارتفاع الحرارة اعلى من
                        <span id="hTempAlarm_point"></span>
                        <div class="hTempAlarm">
                            <div id="hTempAlarm_minval"></div>
                            <input id="hTempAlarm_slidetemp" oninput="updatehTempAlarm_fuc()" style="width: 70%;"
                                type="range" value="0.0" step="0.05" min="0" max="0">
                            <div id="hTempAlarm_maxval"></div>

                        </div>
                    </li>
                    <li>انذار عند انخفاض الحرارة ادنى من
                        <span id="lowTempAlarm_point"></span>
                        <div class="lowTempAlarm">
                            <div id="lowTempAlarm_minval"></div>
                            <input id="lowTempAlarm_slidetemp" oninput="updatelowTempAlarm_fuc()" style="width: 70%;"
                                type="range" value="0.0" step="0.05" min="0" max="0">
                            <div id="lowTempAlarm_maxval"></div>

                        </div>
                    </li>
                    <li id="d"> انذار عند ارتفاع الرطوبة عن
                        <span id="hihumidityAlarm_point"></span>
                        <div class="hihumidityAlarm">
                            <div id="hihumidityAlarm_minval"></div>
                            <input id="hihumidityAlarm_slide" oninput="updatehihumidityAlarm_fuc()" style="width: 70%;"
                                type="range" value="0" step="1" min="30" max="80">
                            <div id="hihumidityAlarm_maxval"></div>

                        </div>
                    </li>
                    <li id="e">انذار عند انخفاض الرطوبة عن
                        <span id="lowhumidityAlarm_point"></span>
                        <div class="lowhumidityAlarm">
                            <div id="lowhumidityAlarm_minval"></div>
                            <input id="lowhumidityAlarm_slide" oninput="updatelowhumidityAlarm_fuc()"
                                style="width: 70%;" type="range" value="0" step="1" min="30" max="80">
                            <div id="lowhumidityAlarm_maxval"></div>

                        </div>
                    </li>
                    <li id="f">
                        <div class="turningset" id="off" onclick="offfunc(notbol)">
                            التقليب لا يعمل
                        </div>

                    </li>
                    <li>مرة باليوم
                        <span id="turningtime_point">2</span>
                        <div class="turningtime">
                            <div id="turningtime_minval">2</div>
                            <input id="turningtime_slide" oninput="updateturningtime_fuc()" style="width: 70%;"
                                type="range" value="2" step="1" min="2" max="12">
                            <div id="turningtime_maxval">12</div>

                        </div>
                    </li>
                    <li>فترة التفقيس
                        <span id="hatching_point">21</span>
                        <div class="hatching">
                            <div id="hatching_minval">18</div>
                            <input id="hatching_slide" oninput="updatehatching_fuc()" style="width: 70%;" type="range"
                                value="21" step="1" min="18" max="32">
                            <div id="hatching_maxval">32</div>

                        </div>
                    </li>
                    <li>
                        <div>تاريخ وضع البيض
                            <br>
                            <input type="datetime-local" id="birthday" value="2021-03-26T20:47"
                                min="2020-10-06T22:22:55" max="2054-11-16T21:25:33">
                        </div>

                    </li>

                    <li class="undo" onclick="settingFunction()">رجوع
                        <div class="save" onclick="savefunc(bol)">حفظ</div>
                    </li>

                </ul>

            </div>

            <div id="demo"></div>

        </div>
    </div>

    <script>
        var myParameter;
        var setTemp, _setTemp;
        var sethiTemp, _sethiTemp;
        var setloTemp, _setloTemp;
        var sethihum, _sethihum;
        var setlohum, _setlohum;
        var bol, _bol;
        var notbol;
        var setturningtime, _setturningtime;
        var hach, _hach;
        var days;
        ///////////////
        var stat = false;
        ////////////////
        var calender;

        function getParameters() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    setParameter(this.responseText);
                }
            };
            xhttp.open("GET", "/getparam", true);
            xhttp.send();
        }

        function getData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {

                    setData(this.responseText);
                    // document.getElementById("demo").innerText = "متصل";

                }
                //  else {
                //     document.getElementById("demo").innerText = "غير متصل";
                // }
            };
            xhttp.open("GET", "/getdata", true);
            xhttp.send();

        }
        document.addEventListener("DOMContentLoaded", () => {
            getParameters();
            getData();
            setInterval(getData, 1000);
        });

        function setParameter(jsonparam) {
            myParameter = JSON.parse(jsonparam);
            var spTemp1 = (myParameter.SETTMP).toFixed(1);
            var spTemp2 = (myParameter.SETTMP).toFixed(2);
            var spthi = (myParameter.TMPHI).toFixed(2);
            var sptlo = (myParameter.TMPLO).toFixed(2);
            var humhi = (myParameter.HHI).toString();
            var humlo = (myParameter.HLO).toString();
            var onoff = (myParameter.TURN);
            bol = onoff, notbol = !bol;
            var period = (myParameter.PERIOD).toString();
            var haching = (myParameter.HACHIN).toString();

            var year = (myParameter.YEAR + 2000).toString();
            var month = (myParameter.MONTH).toString();
            var day = (myParameter.DAY).toString();
            var hour = (myParameter.HOUR).toString();
            var minut = (myParameter.MINUT).toString();

            console.log(spTemp1, spthi, sptlo, humhi, humlo, onoff, period, haching);
            document.getElementById("setTmp_slidetemp").value = spTemp1;
            document.getElementById("setTmp_point").innerText = document.getElementById("setTmp_slidetemp").value;
            document.getElementById("setTmp_maxval").innerText = document.getElementById("setTmp_slidetemp").max;
            document.getElementById("setTmp_minval").innerText = document.getElementById("setTmp_slidetemp").min;
            //////high temp alarm///////
            document.getElementById("hTempAlarm_slidetemp").min = (spTemp2 * 1.00);
            document.getElementById("hTempAlarm_slidetemp").max = ((spTemp2 * 1.00) + 1.50);
            document.getElementById("hTempAlarm_slidetemp").value = spthi;
            document.getElementById("hTempAlarm_minval").innerText = document.getElementById("hTempAlarm_slidetemp").min;
            document.getElementById("hTempAlarm_point").innerText = document.getElementById("hTempAlarm_slidetemp").value;
            document.getElementById("hTempAlarm_maxval").innerText = document.getElementById("hTempAlarm_slidetemp").max;
            /////////////low temp alarm
            document.getElementById("lowTempAlarm_slidetemp").min = ((spTemp2 * 1.00) - 1.50);
            document.getElementById("lowTempAlarm_slidetemp").max = (spTemp2 * 1.00);
            document.getElementById("lowTempAlarm_slidetemp").value = sptlo;
            document.getElementById("lowTempAlarm_minval").innerText = document.getElementById("lowTempAlarm_slidetemp").min;
            document.getElementById("lowTempAlarm_point").innerText = document.getElementById("lowTempAlarm_slidetemp").value;
            document.getElementById("lowTempAlarm_maxval").innerText = document.getElementById("lowTempAlarm_slidetemp").max;
            ////////////////////////////////////////////////////////////
            document.getElementById("hihumidityAlarm_slide").value = humhi;
            document.getElementById("hihumidityAlarm_point").innerText = '%' + document.getElementById("hihumidityAlarm_slide").value;
            document.getElementById("hihumidityAlarm_minval").innerText = document.getElementById("hihumidityAlarm_slide").min + '%';
            document.getElementById("hihumidityAlarm_maxval").innerText = document.getElementById("hihumidityAlarm_slide").max + '%';
            ///////////////////////////////////////////////////////////
            document.getElementById("lowhumidityAlarm_slide").value = humlo;
            document.getElementById("lowhumidityAlarm_point").innerText = '%' + document.getElementById("lowhumidityAlarm_slide").value;
            document.getElementById("lowhumidityAlarm_minval").innerText = document.getElementById("lowhumidityAlarm_slide").min + '%';
            document.getElementById("lowhumidityAlarm_maxval").innerText = document.getElementById("lowhumidityAlarm_slide").max + '%';
            /////////////////////////////////////////////////////////////
            if (onoff) {

                document.getElementById("off").innerText = "التقليب يعمل";
                document.getElementById("off").style = "background: #34db01;;box-shadow: 0px 0px 3px 3px #00ff22;";
                document.getElementById("turningtime_slide").value = period;
                document.getElementById("turningtime_point").innerText = document.getElementById("turningtime_slide").value + " ساعه" + " (" + `${(24 / document.getElementById("turningtime_slide").value).toFixed(2)} مرة باليوم )`;
                setturningtime = document.getElementById("turningtime_slide").value;
            }
            else {

                document.getElementById("off").innerText = "التقليب لا يعمل";
                document.getElementById("off").style = "background-color:#b80101;";
                document.getElementById("turningtime_slide").value = 0;
                document.getElementById("turningtime_point").innerText = "غير متاح";
                setturningtime = document.getElementById("turningtime_slide").value;
            }
            /////////////////////
            document.getElementById("hatching_slide").value = haching;
            document.getElementById("hatching_point").innerText = `${(document.getElementById("hatching_slide").value)} يوم`;
            ////////////////////////////////////////////////////////////
            setTemp = document.getElementById("setTmp_slidetemp").value;
            sethiTemp = document.getElementById("hTempAlarm_slidetemp").value;
            setloTemp = document.getElementById("lowTempAlarm_slidetemp").value;
            sethihum = document.getElementById("hihumidityAlarm_slide").value;
            setlohum = document.getElementById("lowhumidityAlarm_slide").value;

            hach = document.getElementById("hatching_slide").value;

            var sminut,shour,sday,smonth;
            month < 10 ? smonth = "0" + month : smonth = month;
            day < 10 ? sday = "0" + day : sday = day;
            hour < 10 ? shour = "0" + hour : shour = hour;
            minut < 10 ? sminut = "0" + minut : sminut = minut;
            document.getElementById("ii").innerText = year + "/" + month + "/" + day + ". " + hour + ":" + minut + " = تاريخ وضع البيض *";
            document.getElementById("birthday").value = year + "-" + smonth + "-" + sday + "T" + shour + ":" + sminut;
            
            _setTemp = spTemp1;
            _sethiTemp = spthi;
            _setloTemp = sptlo;
            _sethihum = humhi;
            _setlohum = humlo;
            _bol = bol;
            _setturningtime = period;
            _hach = haching;
            updateInfotxt();
        }

        function updateTemp_func() {
            _setTemp = document.getElementById("setTmp_slidetemp").value;
            document.getElementById("setTmp_point").innerText = document.getElementById("setTmp_slidetemp").value;
            ///////////////////////
            document.getElementById("hTempAlarm_slidetemp").min = (_setTemp * 1.00);
            document.getElementById("hTempAlarm_slidetemp").max = ((_setTemp * 1.00) + 1.50);
            document.getElementById("hTempAlarm_slidetemp").value = ((_setTemp * 1.00) + 0.25);
            document.getElementById("hTempAlarm_minval").innerText = document.getElementById("hTempAlarm_slidetemp").min;
            document.getElementById("hTempAlarm_point").innerText = document.getElementById("hTempAlarm_slidetemp").value;
            document.getElementById("hTempAlarm_maxval").innerText = document.getElementById("hTempAlarm_slidetemp").max;
            ////////////////////////
            document.getElementById("lowTempAlarm_slidetemp").max = _setTemp;
            document.getElementById("lowTempAlarm_slidetemp").value = (_setTemp * 1.0) - 0.25;
            document.getElementById("lowTempAlarm_slidetemp").min = (_setTemp * 1.0) - 1.5;
            document.getElementById("lowTempAlarm_minval").innerText = document.getElementById("lowTempAlarm_slidetemp").min;
            document.getElementById("lowTempAlarm_point").innerText = document.getElementById("lowTempAlarm_slidetemp").value;
            document.getElementById("lowTempAlarm_maxval").innerText = document.getElementById("lowTempAlarm_slidetemp").max;
            _setTemp = document.getElementById("setTmp_slidetemp").value;
            _sethiTemp = document.getElementById("hTempAlarm_slidetemp").value;
            _setloTemp = document.getElementById("lowTempAlarm_slidetemp").value;
        }

        function updatehTempAlarm_fuc() {
            _sethiTemp = document.getElementById("hTempAlarm_slidetemp").value;
            document.getElementById("hTempAlarm_point").innerText = document.getElementById("hTempAlarm_slidetemp").value;
        }

        function updatelowTempAlarm_fuc() {
            _setloTemp = document.getElementById("lowTempAlarm_slidetemp").value;
            document.getElementById("lowTempAlarm_point").innerText = document.getElementById("lowTempAlarm_slidetemp").value;
        }

        function updatehihumidityAlarm_fuc() {

            if ((document.getElementById("hihumidityAlarm_slide").value) < (document.getElementById("lowhumidityAlarm_slide").value + "5")) {
                document.getElementById("lowhumidityAlarm_slide").value = document.getElementById("hihumidityAlarm_slide").value - "5";
            }
            document.getElementById("hihumidityAlarm_point").innerText = '%' + document.getElementById("hihumidityAlarm_slide").value;
            document.getElementById("lowhumidityAlarm_point").innerText = '%' + document.getElementById("lowhumidityAlarm_slide").value;
            _sethihum = document.getElementById("hihumidityAlarm_slide").value;
            _setlohum = document.getElementById("lowhumidityAlarm_slide").value;
        }

        function updatelowhumidityAlarm_fuc() {

            if ((document.getElementById("lowhumidityAlarm_slide").value) > (document.getElementById("hihumidityAlarm_slide").value - "5")) {

                document.getElementById("lowhumidityAlarm_slide").value = document.getElementById("hihumidityAlarm_slide").value - "5";
            }
            document.getElementById("hihumidityAlarm_point").innerText = '%' + document.getElementById("hihumidityAlarm_slide").value;
            document.getElementById("lowhumidityAlarm_point").innerText = '%' + document.getElementById("lowhumidityAlarm_slide").value;
            _sethihum = document.getElementById("hihumidityAlarm_slide").value;
            _setlohum = document.getElementById("lowhumidityAlarm_slide").value;
        }

        function offfunc(bb) {

            if (bb) {

                document.getElementById("off").innerText = "التقليب يعمل";
                document.getElementById("off").style = "color: black;  background: #2ec002;box-shadow:  0px 0px 3px 3px #00ff22";
                _bol = true;
                notbol = !_bol;
                document.getElementById("turningtime_slide").value = _setturningtime;
                document.getElementById("turningtime_point").innerText = " ساعه" + " (" + `${(24 / document.getElementById("turningtime_slide").value).toFixed(2)} مرة باليوم )` + document.getElementById("turningtime_slide").value;
                setturningtime = (24 / document.getElementById("turningtime_slide").value).toFixed(2);
            }
            else {
                document.getElementById("off").innerText = "التقليب لا يعمل";
                document.getElementById("off").style = "background-color:#b80101;";
                _bol = false;
                notbol = !_bol;
                document.getElementById("turningtime_slide").value = 0;
                document.getElementById("turningtime_point").innerText = "غير متاح";
                setturningtime = document.getElementById("turningtime_slide").value;
            }

        }

        function updateturningtime_fuc() {
            if (!_bol) {
                document.getElementById("turningtime_slide").value = 0;
                document.getElementById("turningtime_point").innerText = "غير متاح";
                _setturningtime = 0;
            }
            else {
                document.getElementById("turningtime_point").innerText = ` كل ${document.getElementById("turningtime_slide").value} ساعه ` + " (" + `${(24 / document.getElementById("turningtime_slide").value).toFixed(2)} مرة باليوم )`;
                _setturningtime = document.getElementById("turningtime_slide").value;
            }

        }

        function updatehatching_fuc() {
            document.getElementById("hatching_point").innerText = `${(document.getElementById("hatching_slide").value)} يوم`;
            _hach = document.getElementById("hatching_slide").value;
        }

        function updateInfotxt() {
            var F;
            if (_bol) {
                T = "يعمل";
            }
            else {
                T = "لا يعمل";
            }
            document.getElementById("aa").innerText = `.C° ${(_setTemp)}   ...... درجـة الـحـرارة المـطلـوبة *`;
            document.getElementById("bb").innerText = `.C° ${(_sethiTemp)} ...... انذار عنـد ارتـفاع الحـرارة  *`;
            document.getElementById("cc").innerText = `.C° ${(_setloTemp)} ...... انذار عند انخفاض الحرارة  *`;
            document.getElementById("dd").innerText = `.%  ${(_sethihum)}  ...... انذار عنـد ارتفاع الرطـوبة  *`;
            document.getElementById("ee").innerText = `.%  ${(_setlohum)}  ...... انذار عند انخفاض الرطوبة  *`;
            document.getElementById("ff").innerText = `.حالة التقليب = ${(T)}   *`;
            document.getElementById("gg").innerText = `.عدد مرات التقليب = ${(24 / _setturningtime).toFixed(2)}  مرة باليوم الواحد *`;
            document.getElementById("hh").innerText = `.فترة التفقيس = ${(_hach)}  يوم *`;

            document.getElementById("jj").innerText = `.الايام المتبقية للتفقيس = ${(days)}  يوم *`;
        } // 2021-03-26T20:47

        //////////////////////////////////////

        function settingFunction() {

            var setting = document.getElementById("mysetting");
            setting.classList.toggle("show");
            getParameters();
        }

        function savefunc() {///should take the copy of parameters and set to original 
            // 2021-03-26T20:47
            calender = document.getElementById("birthday").value;
            var _x = calender.slice(0, 4);
            var _year = _x - 2000;
            var _month = calender.slice(5, 7);
            var _day = calender.slice(8, 10);
            var _hour = calender.slice(11, 13);
            var _minut = calender.slice(14, 16);
            // document.getElementById("birthday").value=calender;

            setTemp = _setTemp;
            sethiTemp = _sethiTemp;
            setloTemp = _setloTemp;
            sethihum = _sethihum;
            setlohum = _setlohum;
            bol = _bol;
            setturningtime = _setturningtime;
            hach = _hach;
            updateInfotxt();

            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    var checkSave = JSON.parse(this.responseText);
                    // if (
                    //     ((checkSave.SETTMP).toFixed(1) == setTemp)
                    //     //  ((checkSave.TMPHI).toFixed(2) == sethiTemp)
                    //     // && ((checkSave.TMPLO).toFixed(2) == setloTemp)
                    //     // & ((checkSave.HHI).toString() == sethihum)
                    //     // & ((checkSave.HLO).toString() == setlohum)
                    //     // & ((checkSave.PERIOD).toString() == setturningtime)
                    //     // & ((checkSave.HACHIN).toString() == hach)
                    // ) {
                    //     document.getElementById("demo").innerText = "Saving Success!";
                    // }
                    // else
                    //     document.getElementById("demo").innerText = "Saving Fail!";

                }
            };

            xhttp.open("GET", "/saveparam?a=" + setTemp +
                "&b=" + sethiTemp +
                "&c=" + setloTemp +
                "&e=" + sethihum +
                "&f=" + setlohum +
                "&g=" + setturningtime +
                "&h=" + hach +
                "&i=" + bol +
                "&j=" + _year +
                "&k=" + _month +
                "&l=" + _day +
                "&m=" + _hour +
                "&n=" + _minut, true);
            xhttp.send();
            // xhttp.open("POST", "/saveparam", true);
            // xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded")
            // xhttp.send("data=" + JSON.stringify(dataObj));
            getParameters();
        }

        function setData(jsonStr) {

            var myObj = JSON.parse(jsonStr);

            days = myObj.DAYS;

            var mask = 1;

            document.getElementById("demo").innerText = `${(myObj.YEAR)}/${(myObj.MONTH)}/${(myObj.DINM)}/ ${(myObj.HOURS)}:${(myObj.MINUT)}:${(myObj.SEC)}`;
            if (bol) {
                document.querySelector(".turningtxt ").textContent = `${(myObj.SEC)} = الوقت المتبقي للتقليب`;
                document.querySelector(".turninglevel ").style = `width:${((myObj.SEC / 60) * 100)}%`;

                if (myObj.SEC == 0) {

                    document.querySelector(".eggrotate").style = ` animation-iteration-count:${4} `;

                    if (stat) {

                        document.querySelector(".eggrotate").style = `animation-name: eggleft`;

                    } else {

                        document.querySelector(".eggrotate").style = `animation-name: eggright`;
                    }
                    stat = !stat;
                }
            }
            else {
                document.querySelector(".turningtxt ").textContent = `التقليب متوقف `;
                document.querySelector(".turninglevel ").style = `width:${(100)}%`;
            }
            ///////////////////////////
            if (myObj.HUMI > 90 || myObj.HUMI < 0) {
                return;
            } else {
                document.querySelector(".humtxt ").textContent = `% ${(myObj.HUMI)} = الرطوبة الحالية`;

                if ((myObj.HUMI > setlohum) && (myObj.HUMI < sethihum)) {

                    document.querySelector(".thermometerBlue_liquid ").style = ` background-color: rgb(0, 0, 255); width:${myObj.HUMI}% ; 
                    box-shadow: -1px -1px 1px -1px rgba(216, 215, 215, 0.247)inset, 4px 4px 5px 1px rgba(1, 21, 85, 0.986)inset, 3px 4px 10px -3px rgb(0, 162, 255), 0px 7px 0.1px 0px rgba(255, 255, 255, 0.616)inset`;

                } else {

                    document.querySelector(".thermometerBlue_liquid ").style = `background-color: rgb(173, 0, 0); width:${myObj.HUMI}% ; 
                    box-shadow: -1px -1px 1px -1px rgba(216, 215, 215, 0.247)inset, 4px 4px 5px 1px rgba(85, 1, 1, 0.986)inset, 3px 4px 10px -3px rgb(255, 0, 0), 0px 7px 0.1px 0px rgba(255, 255, 255, 0.616)inset`;
                }
            }

            if (myObj.TEMP > 90.0 || myObj.TEMP < 0.0) {
                return;
            } else {
                document.querySelector(".temptxt ").textContent = `C° ${((myObj.TEMP).toFixed(2))} = الحرارة الحالية`;

                if ((myObj.TEMP > setloTemp) && (myObj.TEMP < sethiTemp)) {

                    document.querySelector(".thermometerRed_liquid ").style = `background-color: #10ac10 ; width:${myObj.TEMP}% ; box-shadow: -1px -1px 1px -1px rgba(216, 215, 215, 0.247)inset, 4px 4px 5px 1px rgba(8, 85, 1, 0.986)inset, 3px 4px 10px -3px rgb(51, 255, 0), 0px 7px 0.1px 0px rgba(255, 255, 255, 0.616)inset`;

                } else {

                    document.querySelector(".thermometerRed_liquid ").style = `background-color: rgb(173, 0, 0); width:${myObj.TEMP}% ; box-shadow: -1px -1px 1px -1px rgba(216, 215, 215, 0.247)inset, 4px 4px 5px 1px rgba(85, 1, 1, 0.986)inset, 3px 4px 10px -3px rgb(255, 0, 0), 0px 7px 0.1px 0px rgba(255, 255, 255, 0.616)inset`;
                }
            }

            mask = 1 << 1;
            if ((myObj.GROP & mask) != 0) {///WATER=D1
                document.querySelector(".water ").style.color = " #0077ff ";
            } else {
                document.querySelector(".water ").style.color = " #31343b ";
            }

            mask = 1 << 2;
            if ((myObj.GROP & mask) != 0) {///lamp=D2
                document.querySelector(".lamp").style = `animation-name: lampon`;
            } else {
                document.querySelector(".lamp").style = `animation-name: lampoff`;
            }

            mask = 1 << 3;
            if ((myObj.GROP & mask) != 0) {///DOOR=D3
                document.querySelector(".door ").style.color = " #e41d0f ";
            } else {
                document.querySelector(".door ").style.color = " #31343b ";
            }

            mask = 1 << 5;
            if ((myObj.GROP & mask) != 0) {///FAN=D5
                document.querySelector("#fanpath ").style = `animation-duration:${3}s`;
                document.querySelector("#fanpath ").style.color = " #fcfc01 ";
            } else {
                document.querySelector("#fanpath ").style = `animation-duration:${0}s`;
                document.querySelector("#fanpath ").style.color = " #31343b ";
            }

        }
    </script>
</body>

</html>
)=====";