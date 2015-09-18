/*
 * ExpandCfile
 * https://github.com/student05/新建文件夹
 *
 * Copyright (c) 2015 zonxin
 * Licensed under the MIT license.
 */

'use strict';

var path = require("path");

module.exports = function(grunt) {

  // Please see the Grunt documentation for more information regarding task
  // creation: http://gruntjs.com/creating-tasks
    function expand(content,cwd,count,keepdefine)
    {
        if(count < 0 )  { grunt.fail.warn("There are too much recursion") }

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

  grunt.registerMultiTask('expandCfile', 'The best Grunt plugin ever.', function() {
    // Merge task-specific and/or target-specific options with these defaults.
      var default_options = {recursion:16,keepdefine:false};
    var options = this.options(default_options);

    // Iterate over all specified file groups.
    this.files.forEach(function(f) {
        // Concat specified files.
        var src = f.src.filter(function(filepath) {
          // Warn on and remove invalid source files (if nonull was set).
          if (!grunt.file.exists(filepath)) {
            grunt.log.warn('Source file "' + filepath + '" not found.');
            return false;
          } else {
            return true;
          }
        });
        src = src[0];
        var content = grunt.file.read(src);
        
        expand.list = [];
        content = expand(content,path.dirname(),options.recursion,options.keepdefine);
        // rm comment
        var reg = /\/\*[\w\W]*?\*\/\n?/g;
        content = content.replace(reg,"");

        // Write the destination file.
        grunt.file.write(f.dest, content);

        // Print a success message.
        grunt.log.writeln('File "' + f.dest + '" created.');
    });
  });

};
