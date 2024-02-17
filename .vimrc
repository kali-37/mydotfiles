set laststatus=2
set noshowmode
set number relativenumber
syntax enable
packadd! dracula
colorscheme dracula
set clipboard=unnamedplus
syntax on
call plug#begin()
  
Plug 'https://github.com/preservim/nerdtree', { 'on': 'NERDTreeToggle' }
  
call plug#end()

