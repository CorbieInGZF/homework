    onload = function ()
    {
         var year=new Date().getFullYear(); //获取当前年份
         var sel = document.getElementById ('sel');//获取select下拉列表
       for ( var i = 2016; i < year+6; i++)//循环添加2016到当前年份加3年的每个年份依次添加到下拉列表
       {
           var option = document.createElement ('option');
           option.value = i;
           var txt = document.createTextNode (i);
           option.appendChild (txt);
           sel.appendChild (option);
       }
    }
