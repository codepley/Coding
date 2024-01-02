function customFetch(url, cb){
   setTimeout(function() {
       console.log(url);
       cb();
   }, 5000)
}

customFetch('i am dot com', function(){
   console.log("after fetch");
})