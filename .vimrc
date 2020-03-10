set nocompatible                        " 不使用 vi 的键盘模式，而是使用 vim 的
filetype on                             " 侦测文件类型
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8

set mouse=
set ts=4
set list
set listchars=tab:>-,trail:~            " space: 
set autoread                            " 当文件发生改动时自动载入
set autowrite                           " 当文件发生变化时自动写入

set autoindent
set tabstop=4
set shiftwidth=4                        " 每一级缩进的长度
set expandtab                           " 缩进用空格来表示
set softtabstop=4                       " 编辑模式下按退格键退回缩进的长度

set t_Co=256                            " 显示颜色
"set wildmenu                           " 显示光标当前位置
" set ruler                               "
"set rulerformat=%20(%2*%<%f%=\ %m%r\ %3l\ %c\ %p%%%)
" set cursorline                        " 高亮显示当前行
set confirm                             " 在处理未保存或只读文件的时候，弹出确认

"syntax enable                           " 语法高亮~
syntax on
set fillchars=vert:\ ,stl:\ ,stlnc:\     " 在被分割的窗口间显示空白，便于阅读~
" set incsearch                           " 在搜索时，输入的词句的逐字符高亮(和下面有区别)
" set hlsearch                             " 在搜索时，输入的词句的逐字符高亮
set laststatus=2                         " 总是显示状态行
"
"
" Vim 配置变更自动生效
if has("autocmd")
    autocmd! BufWritePost $MYVIMRC source $MYVIMRC
endif
