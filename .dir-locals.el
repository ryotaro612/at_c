;;; Directory Local Variables            -*- no-byte-compile: t -*-
;;; For more information see (info "(emacs) Directory Variables")

 ((python-ts-mode  
  . ((eglot-server-programs  
      . (((python-mode python-ts-mode) . ("uv" "run" "pyright-langserver" "--stdio"))))
     ;; apheleia をこのプロジェクト用フォーマッタに割り当てる  
     (eval . (setf (alist-get 'atc-uv-ruff apheleia-formatters)  
                   '("uv" "run" "ruff" "format" "--stdin-filename" filepath "-")))  
     (apheleia-formatter . atc-uv-ruff)))  
 (c++-mode . ((eglot-server-programs . (((c++-mode)
                                         "clangd" 
                                         "--query-driver=/opt/homebrew/bin/g++-15"
                                         "--compile-commands-dir=build"))))))
