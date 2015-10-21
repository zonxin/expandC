var path = require("path");
module.exports= function (grunt){

    function createfile(file){
        if(grunt.file.exists(file)){
            grunt.fail.warn("file "+ file + " exists!");
        }
        // create file
        var filename = path.basename(file),
            macro = "__" + path.normalize(file).replace(/[./\\]/g,"_") + "__",
            ext = path.extname(file), 
            content = "#ifndef FILENAME\n#define FILENAME\n\n\n\n#endif";
        grunt.file.write(file,content.replace(/FILENAME/g,macro.toUpperCase()));
        grunt.log.writeln('File "' + file + '" created.');

        // create ".h" 文件
        file = path.join(path.dirname(file), path.basename(file,ext)+".h");
        grunt.file.write(file,'#include "' + filename + '"\n');
        grunt.log.writeln('File "' + file + '" created.');
        
        // add ".h" to main.js
        var main = grunt.config("add")? (grunt.config("add").main || "main.c") : "main.c",
            lastin = /^[\w\W]*#include[\w\W]+?\n/, // find the last #include
            newline = '#include "'+ file + '"\n';
        content = grunt.file.read(main);
        if(lastin.test(content)){
            content = content.replace(lastin,"$&"+newline);
        }else{
            content = newline + content;
        }
        grunt.file.write(main,content);
        grunt.log.writeln("'" + newline.slice(0,-1) + "' >>  " +main );

        var tdir = path.join("./testdata/",path.normalize(file).replace("clib","").replace(/\.h$/,"/"));
        var str="1\n2\n3\n4\n";
        file = tdir + 'test1in.txt';
        grunt.file.write(file,"4\n"+content);
        grunt.log.writeln('File "' + file + '" created.');

        file = tdir + 'test1out.txt';
        grunt.file.write(file,content);
        grunt.log.writeln('File "' + file + '" created.');
        
    }
    grunt.registerTask('add',"add file",createfile);
};
