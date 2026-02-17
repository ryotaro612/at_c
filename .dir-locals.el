;;; Directory Local Variables            -*- no-byte-compile: t -*-
;;; For more information see (info "(emacs) Directory Variables")

((python-mode . ((eglot-server-programs . (((python-mode python-ts-mode) . ("uv" "run" "pyright-langserver" "--stdio"))))
		 (eval . (reformatter-define atc-py-format
					     :program "uv"
					     :args '("run" "ruff" "format" "-")))
		 (eval . (atc-py-format-on-save-mode))))
 (c++-mode . ((eglot-server-programs . (((c++-mode)
                                         "clangd" 
                                         "--query-driver=/opt/homebrew/bin/g++-15"
                                         "--compile-commands-dir=build"))))))
