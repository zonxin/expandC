var path = require("path");
module.exports = function(grunt) {
    // Project configuration.
    grunt.initConfig({
        pkg: grunt.file.readJSON("package.json"),
        
        config:grunt.file.readJSON("expandC.json"),
        compile_cmd: "<%= config.CC %>  "+ 
                     "<%= config.main %> " + 
                     "<%= config.ccArg %> " + 
                     "-o <%= config.output %>",

        expandCfile:{
            main:{
                src:['<%= config.main %>'],
                dest:'<%= config.dest %><%= config.main %>'
            }
        },

        add:{ main:"<%= config.main %>" },

        shell:{
            before:{
                command:"<%= compile_cmd %>"
            },
            beforetest:{
                command:"./<%= config.output %> < <%= config.test %> | " +
                        "<%= config.DIFF %> <%= config.diffArg %> -- - <%= config.test_result %>",
            },
            after:{
                command:"<% if (config.dest) { %> cd <%= config.dest %> && <% } %> <%= compile_cmd %>"
            },
            aftertest:{
                command:"./<%= config.dest %><%= config.output %> < <%= config.test %> |"+
                        " <%= config.DIFF %> <%= config.diffArg %> -- - <%= config.test_result %>"
            }
        },

        watch:{
            files:"<%= config.watchfile %>",
            tasks:['default']
        }
    });
    // load task
    grunt.loadTasks('./tasks');
    grunt.loadNpmTasks("grunt-shell");
    grunt.loadNpmTasks("grunt-contrib-watch");
    
    // 默认被执行的任务列表。
    grunt.registerTask('pretest', ['shell:before','shell:beforetest']);
    grunt.registerTask('build', ['expandCfile']);
    grunt.registerTask('finaltest', ['build','shell:after','shell:aftertest']);

    grunt.registerTask('default', ['finaltest']);
};




