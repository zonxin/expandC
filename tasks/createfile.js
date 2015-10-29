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
            head =  "#ifndef FILENAME\n#define FILENAME\n",
            tail = "\n#endif\n",
            content = grunt.file.read("template/clib.c");
        var fn = path.basename(filename,ext),
            regFn = /\{\{\s*@FN\s*\}\}/g;
        content = head.replace(/FILENAME/g,macro.toUpperCase()) +
                  content.replace(regFn,fn) +
                  tail.replace(/FILENAME/,macro.toUpperCase());
        grunt.file.write(file,content.replace(/FILENAME/g,macro.toUpperCase()));
        grunt.log.writeln('File "' + file + '" created.');

        // create ".h" 文件
        file = path.join(path.dirname(file), path.basename(file,ext)+".h");
        if(grunt.file.exists(file)){
            grunt.fail.warn("file "+ file + " exists!");
        }
        grunt.file.write(file,'#include "' + filename + '"\n');
        grunt.log.writeln('File "' + file + '" created.');
        
        // create main.c and add ".h" to main.c
        var main = "template/main.c",
            lastin = /^[\w\W]*#include[\w\W]+?\n/, // find the last #include
            newline = '#include "'+ file + '"\n',
            testpath = /TestFilePath:(\S*)/;
        content = grunt.file.read(main);
        if(lastin.test(content)){
            content = content.replace(lastin,"$&"+newline);
        }else{
            content = content.replace(/\n.*\n.*\n/,"$&"+newline);
        }
        var tdir = path.join("./testdata/",path.normalize(file).replace("clib","").replace(/\.h$/,"/"));
        content = content.replace(testpath,"TestFilePath:"+tdir);
        content = content.replace(regFn,fn);
        main = tdir + 'main.c';
        grunt.file.write(main,content);
        grunt.log.writeln('File "' + main + '" created.');
        //creat readme.md
        content = "# QUESTIION\n\n## Input\n\n## Output\n\n\n";
        file = tdir + 'readme.md';
        grunt.file.write(file,content);
        grunt.log.writeln('File "' + file + '" created.');
        //created test1in/out.txt
        content="4\n1\n2\n3\n4\n";
        file = tdir + 'test1in.txt';
        grunt.file.write(file,content);
        grunt.log.writeln('File "' + file + '" created.');
        content="0\n";
        file = tdir + 'test1out.txt';
        grunt.file.write(file,content);
        grunt.log.writeln('File "' + file + '" created.');
    }
    grunt.registerTask('add',"add file",createfile);
};
