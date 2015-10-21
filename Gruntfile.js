var path = require("path");


  // Please see the Grunt documentation for more information regarding task
  // creation: http://gruntjs.com/creating-tasks

module.exports = function(grunt) {
    // Project configuration.
    grunt.initConfig({
        pkg: grunt.file.readJSON("package.json"),
        config:grunt.file.readJSON("expandC.json"),

        add:{ main:"<%= config.main %>" },

        shell:{ make:{ command:"make" }},

        watch:{
            files:"<%= config.watchfile %>",
            tasks:['default']
        }
    });
    // load task
    grunt.loadTasks('./tasks');
    grunt.loadNpmTasks("grunt-shell");
    grunt.loadNpmTasks("grunt-contrib-watch");
    
    grunt.registerTask('build', function(input,output){
        var options = { recursion:16,keepdefine:false };
        var src = input||'main.c';
        var content = grunt.file.read(src);
        
        expand.list = [];
        content = expand(content,path.dirname(),options.recursion,options.keepdefine);
        // rm comment
        var reg = /\/\*[\w\W]*?\*\/\n?/g;
        content = content.replace(reg,"");
        reg = /\n+/g;
        //删除多余的换行
        content = content.replace(reg,"\n");

        // Write the destination file.
        var dest = output||'dest/'+src;
        grunt.file.write(dest, content);

        // Print a success message.
        grunt.log.writeln('File "' + dest + '" created.');
    });

    grunt.registerTask('default', ['shell:make']);

    function expand(content,cwd,count,keepdefine)
    {
        if(count < 0 )  { grunt.fail.warn("There are too much recursion"); }

        var regx = /#include\s*"([\w.\\/]+?)"/g; // include file

        content = content.replace(regx,function(str,filename){
            var fullpath = path.join(cwd,filename);
            fullpath = path.normalize(fullpath);
            // 防止重复包含同一个文件
            var i;
            for(i=0;i<expand.list.length;i++){
                if( expand.list[i] === fullpath){
                    grunt.log.writeln("skip "+ fullpath+ " because it has been included.") ;
                    return "";
                }
            }
            expand.list.push(fullpath);

            grunt.log.writeln("Entering "+ fullpath + "...");
            var code = grunt.file.read(fullpath);
            if(!keepdefine){
                code = code.replace(/^[\w\W]*?#define.*?\n/,""); // first define and before it
                code = code.replace(/#endif\s*$/,""); // 最后一个#endif
            }

            return expand(code,path.dirname(fullpath),count-1,keepdefine);
        });
        return content;
    }
    expand.list =[];
};




