
function jump(g)
{
    const title = g.querySelector("title").innerHTML;
    const dest = document.getElementById(title.split("-&gt")[0]);
    dest.scrollIntoView(true);


    dest.querySelector("text").setAttribute("stroke",  "#1b75b3");
    
    setTimeout(() => { dest.querySelector("text").setAttribute("stroke", "none")}, 3000);


}

function prettyname(name)
{
    return name.split("_").join(" ");
}

function preview(g)
{
    const popup = document.createElement("div");
    const term = document.createElement("p");
    const term2 = document.createElement("p");
    const arrow = document.createElement("p");
    const terms = g.querySelector("title").innerHTML.split("-&gt;");

    
    term.innerHTML = prettyname(terms[0]);
    term2.innerHTML = prettyname(terms[1]);
    arrow.innerHTML = "&rarr;";

    popup.appendChild(term);
    popup.appendChild(arrow);
    popup.appendChild(term2);

    popup.id = g.id + "POPUP";
    popup.style.left = window.event.clientX + window.scrollX + "px"; 
    popup.style.top = window.event.clientY + window.scrollY + "px"; 
    popup.className = "popup";

    g.setAttribute("o_title", g.querySelector("title").innerHTML);
    g.querySelector("title").innerHTML = "";

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

    let title = g.querySelector("title");
    title.innerHTML = g.getAttribute("o_title");

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
        const title = node.querySelector("title");
        node.id = title.innerHTML; 
        node.querySelector("text").innerHTML = prettyname(title.innerHTML);

    });
}
main(); 
