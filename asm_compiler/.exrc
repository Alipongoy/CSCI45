if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
nmap gx <Plug>NetrwBrowseX
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set background=dark
set backspace=2
set history=50
set ignorecase
set matchtime=0
set nomodeline
set printoptions=paper:a4
set ruler
set runtimepath=~/.vim,~/.vim/bundle/Vundle.vim,~/.vim/bundle/vim-colors-solarized,~/.vim/bundle/molokai,~/.vim/bundle/gruvbox,~/.vim/bundle/vim-airline,~/.vim/bundle/gruvbox,~/.vim/bundle/molokai,~/.vim/bundle/vim-airline,~/.vim/bundle/vim-colors-solarized,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim73,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after,~/.vim/bundle/Vundle.vim/after,~/.vim/bundle/vim-colors-solarized/after,~/.vim/bundle/molokai/after,~/.vim/bundle/gruvbox/after,~/.vim/bundle/vim-airline/after
set shiftwidth=4
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tabstop=4
set undolevels=0
set visualbell
" vim: set ft=vim :
