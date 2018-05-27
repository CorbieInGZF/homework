// JavaScript Document
$(function () {
    //点击登陆按钮时进行的判断
    $(".but").on("click", function () {
        if ($("#usertxt").val() == "" || $("#pwdtxt").val() == "") {
            $(".Error_prompt").fadeIn(800).html("<b>用户名或密码不能为空！</b>");
            return false;
        } else {
            $(".Error_prompt").fadeOut(400);
            //前端初步判断数据类型成功以后像后台发出请求来判断登陆是否成功
            $.ajax({
                type: "post",
                url: "http://localhost:8080/user/login",
                dataType: "json",
                data: {"username":$("#usertxt").val(),"password":$("#pwdtxt").val()},
                success: function (data) {
                    var result = data.code;
                    //用户名和密码校验错误
                    if (result == "100"||result == "200") {
                        $(".Error_prompt").fadeIn(800).html("该用户不存在或密码错误");
                        $(".Error_prompt").fadeIn("fast", "linear");
                        
                    }
                    else if(result == "300"){
                        window.location.href = "班会记录.html";
                    }
                    else if(result == "400"){
                        window.location.href = "班会记录.html";
                    }
                },
                error: function (err) {
                    alert(err);
                }
            });
        }
    });
    //用户键盘按下enter键判断的事件
    document.onkeypress = function (event) {
        e = event ? event : (window.event ? window.event : null);
        var currKey = 0;
        currKey = e.keyCode || e.which || e.charCode;
        if (currKey == 13) {
            if ($("#usertxt").val() == "" || $("#pwdtxt").val() == "") {
                $(".Error_prompt").fadeIn(800).html("<b>用户名或密码不能为空！</b>");
                return false;
            } else {
                $(".Error_prompt").fadeOut(400);
            //前端初步判断数据类型成功以后像后台发出请求来判断登陆是否成功
            $.ajax({
                type: "post",
                url: "http://localhost:8080/user/login",
                dataType: "json",
                data: {"username":$("#usertxt").val(),"password":$("#pwdtxt").val(),},
                success: function (data) {
                    var result = data.code;
                    //用户名和密码校验错误
                    if (result == "100"||result == "200") {
                        $(".Error_prompt").fadeIn(800).html("该用户不存在或密码错误");
                        $(".Error_prompt").fadeIn("fast", "linear");
                    }
					else if(result == "300"){
						window.location.href = "班会记录.html";
					}
					else if(result == "400"){
						window.location.href = "班会记录.html";
					}
                },
                error: function (err) {
                    alert(err);
                }
                });
            }
        }
    };
});