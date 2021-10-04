
function jump(g)
{
    const title = g.querySelector("title").innerHTML;
    console.log(title);
    const dest = document.getElementById(title.split("-&gt")[0]);
    dest.scrollIntoView(true);


    dest.querySelector("text").setAttribute("stroke",  "#1b75b3");
    
    setTimeout(() => { dest.querySelector("text").setAttribute("stroke", "none")}, 3000);


}

function preview(g)
{
    const popup = document.createElement("div");
    const term = document.createElement("p");
    const term2 = document.createElement("p");
    const terms = g.querySelector("title").innerHTML.split("-&gt;");

    
    
    term.innerHTML = terms[0];
    term2.innerHTML = terms[1];

    popup.appendChild(term);
    popup.appendChild(term2);

    popup.id = g.id + "POPUP";
    popup.style.left = window.event.clientX + "px"; 
    popup.style.top = window.event.clientY + "px"; 
    popup.className = "popup";

    document.body.appendChild(popup);
    console.log(popup);

}

function remove_preview(g)
{
    let e = document.getElementById(g.id + "POPUP");
    if (e != null) 
    {
        e.parentNode.removeChild(e);
    }



}

function main()
{
    
    const paths = document.querySelectorAll(".edge");

    paths.forEach(path => {


        path.onclick = () => {
            jump(path);    
        }; 

        path.onmouseover = () => {
            preview(path);
        };

        path.onmouseout = () => {
            remove_preview(path);
        };
             


    });

    const nodes = document.querySelectorAll(".node");

    nodes.forEach(node => {
        const title = node.querySelector("title").innerHTML;
        node.id = title; 
    });
}
main(); 
