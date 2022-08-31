var i = 0;
var lineArr;

function reader(){
	document.getElementById("sb_form_q").value = lineArr[i];
	console.log(lineArr[i]);
	i++;
}


function readTextFile(file)
{
    var rawFile = new XMLHttpRequest();
    rawFile.open("GET", file, true);
    var allText;
    rawFile.onreadystatechange = function ()
    {
        if(rawFile.readyState === 4)
        {
            if(rawFile.status === 200 || rawFile.status == 0)
            {
                allText = rawFile.responseText;
                console.log(allText);
                //lineArr = allText.split('\n');
                //setInterval(reader, 5000);
                //alert(allText);
                //window.alert(1+2);
            }
        }
    }
    window.alert(allText);
    rawFile.send(null);
}

readTextFile("file:///home/dell/Desktop/SEM_5/Mini_Project/1letterwords.txt");