let int;
let time = 0;
let score = parseInt(localStorage.getItem("score"));

function onClick_study(){
    let text = document.getElementById("btn-study").innerHTML;
    document.getElementById("score-show").innerHTML = score.toString();
    if(document.getElementById("score-show").innerHTML == "NaN"){
        score = 0;
    }
    if(text == "开始学习"){
        int = self.setInterval("clock()",1000);
        document.getElementById("btn-study").innerHTML = "停止学习";
    }else if(text == "停止学习"){
        int = window.clearInterval(int);
        time = 0;
        document.getElementById("btn-study").innerHTML = "开始学习";
    }
}

function clock(){
    time+=1;
    document.getElementById("time-show").innerHTML = time.toString() + "秒";
    if(time % 60 == 0){
        score+=1;
        localStorage.setItem("score",score.toString());
        document.getElementById("score-show").innerHTML = score.toString();
    }
    console.log("学习时长:"+time.toString());
}