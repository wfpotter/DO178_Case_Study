// Copyright 2014 The MathWorks, Inc.

(function() {

    function fixAbsolutePath() {
        try {
            var baseURI = document.baseURI;
            if (typeof(baseURI) !== "string"){
                if (document.location) baseURI = document.location.href;
                if (typeof(baseURI) !== "string") baseURI =  window.location.href;
                if (typeof(baseURI) !== "string") baseURI = document.URL.replace("\\", "/");
            }
            var path = baseURI.substring(0, baseURI.lastIndexOf("/"));
            var aList = document.getElementsByTagName("a");
            for (var i = 0; i < aList.length; i++) {
                var href = aList[i].href;
                if (href !== "string" && href.search(/^file:\/\//)!=-1 && href.search(/\.html$/)!=-1) {
                    var idx = href.lastIndexOf("/");
                    if (idx) {
                        aList[i].setAttribute("href", path + href.substring(idx));
                    }
                }
            }
        } catch (err) {}
    }

    // Register the listener
    if (window.addEventListener) {
        window.addEventListener("load", fixAbsolutePath, false);
    } else if (window.attachEvent) {
        window.attachEvent("onload", fixAbsolutePath);
    }

})();
