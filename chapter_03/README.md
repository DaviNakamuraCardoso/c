

# Chapter 03 - Do one thing and do it well
## Creating small tools
In this chapter we will build a program that parses data from CSV to JSON

### Problems

#### Pool Puzzle
```c
#include <stdio.h>

int main(void)
{
    float latitude;
    float longitude;
    char info[80];

    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3)
    {
        if ((latitude > 26) && (latitude < 34))
        {
            if ((longitude > -76) && (longitude < -64))
            {
                printf("%f,%f,%s", latitude, longitude, info);
            }

        }
    }
    return 0; 

}

```

#### TOP SECRET
Message 1: *The submarine will surface at 9PM*
Message 2: *Buy six eggs and some milk*

```html

<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="initial-scale=1.0, user-scalable=no">
    <meta charset="utf-8">
    <title>Head First C Map</title>
    <style>
      html, body {
        height: 100%;
        margin: 0;
        padding: 0;
      }
      #map {
        height: 100%;
      }
    </style>
  </head>
  <body>

    <script src="output.json" type="text/javascript">
    </script>
    <script type="text/javascript" src="http://maps.google.com/maps/api/js?sensor=false">
                 </script>

    <div style="overflow:hidden;height:100%;width:100%;">
      <div id="gmap_canvas" style="height:100%;width:100%;"></div>
      <style>#gmap_canvas img{max-width:none!important;background:none!important}</style>
                 </div>
    <script type="text/javascript">
function init_map(){
    var c_lat = 0;
    var c_lon = 0;
    for (var i = 0; i < data.length; i++) {
        c_lat += data[i].latitude;
        c_lon += data[i].longitude;
    }
    if (data.length > 0) {
        c_lat /= data.length;
        c_lon /= data.length;
    }

    var myOptions = {zoom:14,center:new google.maps.LatLng(c_lat,c_lon),mapTypeId: google.maps.MapTypeId.ROADMAP};
    map = new google.maps.Map(document.getElementById("gmap_canvas"), myOptions);

    for (var i = 0; i < data.length; i++) {
        (function fred(data, i) {
            var lat = data[i].latitude;
            if ((lat < -90) || (lat > 90)) {
              alert("Invalid latitude: '" + lat + "'");
              return;
            }
            var lng = data[i].longitude;
            if ((lng < -90) || (lng > 90)) {
              alert("Invalid longitude: '" + lng + "'");
              return;
            }
            var marker = new google.maps.Marker({map: map,position: new google.maps.LatLng(lat, lng)});
            var infowindow = new google.maps.InfoWindow({content:data[i].info });
            google.maps.event.addListener(marker, "click", function(){
                infowindow.open(map,marker);});
        })(data, i);
    }
}

google.maps.event.addDomListener(window, 'load', init_map);
   </script>
  </body>
</html>

```
