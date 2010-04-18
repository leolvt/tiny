# set latexfile to the name of the main file without the .tex
latexfile = doc
FIGDIR = 

TEX = latex
PDFTEX = pdflatex
BIBTEX = bibtex

# =================================== #

.phony: pdf tarball clean mrproper

pdf : $(latexfile).pdf

tarball: $(latexfile).tar.gz

clean:
	@echo "Limpando..."
	@rm -f *.aux *.log *.bbl *.blg
	
mrproper: clean
	@echo "Removendo arquivo final"
	@rm -f *.dvi *.ps *.pdf

# reruns latex if needed.  to get rid of this capability, delete the
# three lines after the rule. 
# idea from http://ctan.unsw.edu.au/help/uk-tex-faq/Makefile
$(latexfile).pdf: $(latexfile).tex
	$(PDFTEX) $(latexfile)
	$(BIBTEX) $(latexfile)
	$(PDFTEX) $(latexfile)
	$(PDFTEX) $(latexfile)	


$(latexfile).tar.gz : $(latexfile).tex
	tar -czvf $(latexfile).tar.gz $(latexfile).tex $(FIGDIR)
